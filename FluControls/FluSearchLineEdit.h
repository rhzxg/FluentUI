#pragma once

#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>

#include "../FluUtils/FluUtils.h"
#include <QPaintEvent>
#include <QStyleOption>
#include <QPainter>
#include <QPaintEvent>
#include <QPainterPath>

class FluSearchLineEdit : public FluWidget
{
    Q_OBJECT
  public:
    FluSearchLineEdit(QWidget* parent = nullptr) : FluWidget(parent)
    {
        m_hLayout = new QHBoxLayout;
        setLayout(m_hLayout);
        m_hLayout->setContentsMargins(1, 0, 1, 0);
        m_hLayout->setSpacing(0);
        m_hLayout->setAlignment(Qt::AlignHCenter);

        m_edit = new QLineEdit(this);
        m_btn = new QPushButton(this);
        m_btn->setFixedSize(30, 20);
        m_btn->setIconSize(QSize(18, 18));
        m_btn->setIcon(FluIconUtils::getFluentIcon(FluAwesomeType::Search));

        m_edit->setFixedHeight(30);

        m_hLayout->addWidget(m_edit, 1);
        m_hLayout->addWidget(m_btn);
        m_hLayout->addSpacing(4);

        // setFixedWidth(155);
        setFixedHeight(32);

        m_edit->installEventFilter(this);
        m_edit->setFocusPolicy(Qt::ClickFocus);

        connect(m_btn, &QPushButton::clicked, [=]() { emit onSearchBtnClicked(); });

        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluSearchLineEdit.qss", this);
    }

    QString getText()
    {
        return m_edit->text();
    }

    void setText(QString text)
    {
        m_edit->setText(text);
    }

    void setPlaceholderText(QString text)
    {
        m_edit->setPlaceholderText(text);
    }

    QString getPlaceholderText()
    {
        return m_edit->placeholderText();
    }

    bool eventFilter(QObject* watched, QEvent* event)
    {
        if (watched == m_edit)
        {
            if (event->type() == QEvent::FocusIn)
            {
                setProperty("isFocused", true);
                style()->polish(this);
                // LOG_DEBUG << "focuse in";
            }
            else if (event->type() == QEvent::FocusOut)
            {
                setProperty("isFocused", false);
                style()->polish(this);
                // LOG_DEBUG << "focuse out";
            }
            else if (event->type() == QEvent::KeyRelease)
            {
                QKeyEvent* keyEvent = (QKeyEvent*)event;
                if (keyEvent->key() == Qt::Key_Return)
                {
                    emit onSearchBtnClicked();
                }
            }
        }

        return QWidget::eventFilter(watched, event);
    }

    void paintEvent(QPaintEvent* event)
    {
        QStyleOption opt;
        opt.initFrom(this);
        QPainter painter(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

        if (!property("isFocused").toBool())
            return;

        FluStyleSheetUitls::drawBottomLineIndicator(this, &painter);
    }
  signals:
    void onSearchBtnClicked();
  public slots:
    void onThemeChanged()
    {
        if (FluThemeUtils::isLightTheme())
        {
            m_btn->setIcon(FluIconUtils::getFluentIcon(FluAwesomeType::Search, FluTheme::Light));
            FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluSearchLineEdit.qss", this);
        }
        else
        {
            m_btn->setIcon(FluIconUtils::getFluentIcon(FluAwesomeType::Search, FluTheme::Dark));
            FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluSearchLineEdit.qss", this);
        }
    }

  protected:
    QLineEdit* m_edit;
    QPushButton* m_btn;
    QHBoxLayout* m_hLayout;
};
