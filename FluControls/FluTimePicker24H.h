#pragma once

#include "../FluUtils/FluUtils.h"
#include <QPushButton>
#include "FluWidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QStyleOption>
#include <QPainter>

#include "FluTimePicker24HView.h"

class FluTimePicker24H : public FluWidget
{
    Q_OBJECT
  public:
    FluTimePicker24H(bool withSecond = false, QWidget* parent = nullptr)
        : FluWidget(parent), m_withSecond(withSecond)
    {
        m_hMainLayout = new QHBoxLayout;
        m_hMainLayout->setContentsMargins(0, 0, 0, 0);
        m_hMainLayout->setSpacing(0);
        setLayout(m_hMainLayout);

        m_hourBtn = new QPushButton;
        m_hourBtn->setText("hour");
        m_hourBtn->setObjectName("hourBtn");

        m_minuteBtn = new QPushButton;
        m_minuteBtn->setText("minute");
        m_minuteBtn->setObjectName("minuteBtn");

        m_hourBtn->setFixedHeight(30);
        m_minuteBtn->setFixedHeight(30);

        m_hMainLayout->addWidget(m_hourBtn);
        m_hMainLayout->addWidget(m_minuteBtn);

        if (withSecond)
        {
            m_secondBtn = new QPushButton;
            m_secondBtn->setText("second");
            m_secondBtn->setObjectName("secondBtn");
            m_secondBtn->setFixedHeight(30);
            m_hMainLayout->addWidget(m_secondBtn);

            connect(m_secondBtn, &QPushButton::clicked, [=]() { emit clicked(); });
        }

        m_timerPicker24HView = new FluTimePicker24HView(withSecond);
        // m_timerPicker24HView->setFixedWidth(240);
        m_timerPicker24HView->hide();

        setFixedSize(300, 30);
        connect(m_hourBtn, &QPushButton::clicked, [=]() { emit clicked(); });
        connect(m_minuteBtn, &QPushButton::clicked, [=]() { emit clicked(); });
        connect(this, &FluTimePicker24H::clicked, [=]() {
            // get current time
            // LOG_DEBUG << "Called";
            // show FluTimerPickerView

            int    nX     = 0;
            int    nY     = m_withSecond ? -410 : height() / 2 - 180;
            QPoint gPoint = mapToGlobal(QPoint(nX, nY));
            m_timerPicker24HView->move(gPoint.x(), gPoint.y());
            m_timerPicker24HView->show();
        });

        connect(m_timerPicker24HView, &FluTimePicker24HView::clickedOk, [=]() {
            QString sHour = QString::asprintf("%02d", m_timerPicker24HView->getHour());
            m_hourBtn->setText(sHour);

            QString sMinute = QString::asprintf("%02d", m_timerPicker24HView->getMinute());
            m_minuteBtn->setText(sMinute);

            QString sSecond;
            if (withSecond)
            {
                sSecond = QString::asprintf("%02d", m_timerPicker24HView->getSecond());
                m_secondBtn->setText(sSecond);
            }

            QString format = withSecond ? "hhmmss" : "hhmm";
            QString time   = withSecond ? sHour + sMinute + sSecond : sHour + sMinute;
            emit    selectedTime(QTime::fromString(time, format));
        });

        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluTimePicker24H.qss", this);
    }

    void mouseReleaseEvent(QMouseEvent* event)
    {
        emit clicked();
    }

    void paintEvent(QPaintEvent* event)
    {
        QStyleOption opt;
        opt.initFrom(this);
        QPainter painter(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
    }

    QTime getCurTime()
    {
        QString sHour = QString::asprintf("%02d", m_timerPicker24HView->getHour());
        QString sMinute = QString::asprintf("%02d", m_timerPicker24HView->getMinute());

        QString sSecond;
        if (m_withSecond)
        {
            sSecond = QString::asprintf("%02d", m_timerPicker24HView->getSecond());
        }

        QString format = m_withSecond ? "hhmmss" : "hhmm";
        QString time   = m_withSecond ? sHour + sMinute + sSecond : sHour + sMinute;
        return QTime::fromString(format, time);
    }

    void setCurTime(QTime time)
    {
        m_hourBtn->setText(QString("%1").arg(time.hour(), 2, 10, QChar('0')));
        m_minuteBtn->setText(QString("%1").arg(time.minute(), 2, 10, QChar('0')));

        if (m_withSecond)
        {
            m_secondBtn->setText(QString("%1").arg(time.second(), 2, 10, QChar('0')));
        }

        m_timerPicker24HView->setHour(time.hour());
        m_timerPicker24HView->setMinute(time.minute());
        m_timerPicker24HView->setSecond(time.second());
    }

  signals:
    void clicked();
    void selectedTime(QTime time);

  public slots:
    void onThemeChanged()
    {
        if (FluThemeUtils::isLightTheme())
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluTimePicker24H.qss", this);
        }
        else
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluTimePicker24H.qss", this);
        }
    }

  protected:
    QHBoxLayout* m_hMainLayout;
    QPushButton* m_hourBtn;
    QPushButton* m_minuteBtn;
    QPushButton* m_secondBtn;

    FluTimePicker24HView* m_timerPicker24HView;

    bool m_withSecond;
};
