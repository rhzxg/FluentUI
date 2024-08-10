#pragma once

#include "FluWidget.h"
#include "FluLoopView.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "../FluUtils/FluUtils.h"
#include <QPainter>
#include <QStyleOption>

class FluTimePicker24HView : public FluWidget
{
    Q_OBJECT
  public:
    FluTimePicker24HView(bool withSecond = false, QWidget* parent = nullptr)
        : FluWidget(parent), m_bFirstShow(true), m_bWithSecond(withSecond)
    {
        setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);

        m_vMainLayout = new QVBoxLayout;
        m_vMainLayout->setContentsMargins(0, 0, 0, 0);
        m_vMainLayout->setSpacing(0);
        setLayout(m_vMainLayout);

        m_hViewLayout = new QHBoxLayout;
        // setLayout(m_hViewLayout);
        m_vMainLayout->addLayout(m_hViewLayout);

        m_hourView = new FluLoopView(100);
        m_minuteView = new FluLoopView(100);

        // set hour data;
        std::vector<QString> datas;
        for (int i = 0; i < 24; i++)
        {
            QString str = QString::asprintf("%02d", i);
            datas.push_back(str);
        }
        m_hourView->setAllItems(datas);

        // set minute data;
        datas.clear();
        for (int i = 0; i < 60; i++)
        {
            QString str = QString::asprintf("%02d", i);
            datas.push_back(str);
        }
        m_minuteView->setAllItems(datas);

        m_hViewLayout->setSpacing(0);
        m_hViewLayout->addWidget(m_hourView);
        m_hViewLayout->addWidget(m_minuteView);

        if (withSecond)
        {
            m_secondView = new FluLoopView(100);
            m_secondView->setAllItems(datas);
            m_hViewLayout->addWidget(m_secondView);
        }

        m_hBtnLayout = new QHBoxLayout;
        m_hBtnLayout->setContentsMargins(5, 5, 5, 5);

        m_okBtn = new QPushButton;
        m_cancelBtn = new QPushButton;

        m_okBtn->setObjectName("okBtn");
        m_cancelBtn->setObjectName("cancelBtn");

        m_okBtn->setFixedHeight(40);
        m_cancelBtn->setFixedHeight(40);

        m_okBtn->setIconSize(QSize(25, 25));
        m_okBtn->setIcon(FluIconUtils::getFluentIcon(FluAwesomeType::Accept));

        m_cancelBtn->setIconSize(QSize(25, 25));
        m_cancelBtn->setIcon(FluIconUtils::getFluentIconPixmap(FluAwesomeType::Cancel));

        m_hBtnLayout->addWidget(m_okBtn);
        m_hBtnLayout->addWidget(m_cancelBtn);

        m_vMainLayout->addLayout(m_hBtnLayout);

        setMinute(0);
        setHour(0);

        connect(m_okBtn, &QPushButton::clicked, [=]() {
            updateTime();
            emit clickedOk();
            close();
        });
        connect(m_cancelBtn, &QPushButton::clicked, [=]() {
            emit clickedCancel();
            close();
        });

        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluTimePicker24HView.qss", this);
    }

    int getHour()
    {
        return m_hour;
    }

    int getMinute()
    {
        return m_minute;
    }

    int getSecond()
    {
        return m_second;
    }

    void setHour(int hour)
    {
        m_hour = hour;
        m_hourView->setVisibaleMidIndex(hour);
        // m_hourView->scrollTo(hour);
    }

    void setMinute(int minute)
    {
        m_minute = minute;
        m_minuteView->setVisibaleMidIndex(minute);
        // m_hourView->scrollTo(minute);
    }

    void setSecond(int second)
    {
        m_second = second;
        m_secondView->setVisibaleMidIndex(second);
        // m_hourView->scrollTo(minute);
    }

    void updateTime()
    {
        m_hour = m_hourView->getVisibleMidIndex();
        m_minute = m_minuteView->getVisibleMidIndex();

        if (m_bWithSecond)
        {
            m_second = m_secondView->getVisibleMidIndex();
        }
    }

    void paintEvent(QPaintEvent* event)
    {
        QStyleOption opt;
        opt.initFrom(this);
        QPainter painter(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
    }

    void showEvent(QShowEvent* event)
    {
        FluWidget::showEvent(event);
        if (!m_bFirstShow)
            return;

        m_bFirstShow = false;
        m_hourView->scrollTo(m_hour);
        m_minuteView->scrollTo(m_minute);

        if (m_bWithSecond)
        {
            m_secondView->scrollTo(m_second);
        }
    }
  signals:
    void clickedOk();
    void clickedCancel();
  public slots:
    void onThemeChanged()
    {
        if (FluThemeUtils::isLightTheme())
        {
            m_okBtn->setIcon(FluIconUtils::getFluentIcon(FluAwesomeType::Accept, FluTheme::Light));
            m_cancelBtn->setIcon(FluIconUtils::getFluentIconPixmap(FluAwesomeType::Cancel, FluTheme::Light));

            FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluTimePicker24HView.qss", this);
        }
        else
        {
            m_okBtn->setIcon(FluIconUtils::getFluentIcon(FluAwesomeType::Accept, FluTheme::Dark));
            m_cancelBtn->setIcon(FluIconUtils::getFluentIconPixmap(FluAwesomeType::Cancel, FluTheme::Dark));
            FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluTimePicker24HView.qss", this);
        }
    }

  protected:
    QVBoxLayout* m_vMainLayout;
    QHBoxLayout* m_hViewLayout;
    QHBoxLayout* m_hBtnLayout;

    FluLoopView* m_hourView;
    FluLoopView* m_minuteView;
    FluLoopView* m_secondView;

    QPushButton* m_okBtn;
    QPushButton* m_cancelBtn;

    int m_hour;
    int m_minute;
    int m_second;

    bool m_bFirstShow;
    bool m_bWithSecond;
};
