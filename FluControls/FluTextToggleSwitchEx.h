#pragma once

#include "FluToggleSwitchEx.h"
#include "FluLabel.h"

#include <QHBoxLayout>

class FluTextToggleSwitchEx : public FluWidget
{
    Q_OBJECT
  public:
    FluTextToggleSwitchEx(QWidget* parent = nullptr)
        : FluWidget(parent)
    {
        m_hMainLayout = new QHBoxLayout;
        m_hMainLayout->setContentsMargins(0, 0, 0, 0);
        setLayout(m_hMainLayout);

        m_toggleSwithEx = new FluToggleSwitchEx;
        m_textLabel     = new FluLabel;
        m_textLabel->setLabelStyle(FluLabelStyle::BodyTextBlockStyle);
        m_textLabel->setWordWrap(true);

        m_hMainLayout->addWidget(m_toggleSwithEx);
        m_hMainLayout->addWidget(m_textLabel);

        setText("on", "off");
        m_textLabel->setText(m_offText);
        connect(m_toggleSwithEx, &FluToggleSwitchEx::toggled, [=](bool bChecked) {
            if (bChecked)
            {
                m_textLabel->setText(m_onText);
            }
            else
            {
                m_textLabel->setText(m_offText);
            }

            emit stateChanged(bChecked);
        });

        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluTextToggleSwithEx.qss", this);
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
    }

    void setText(QString onText, QString offText)
    {
        // m_textLabel->setText(text);
        m_onText  = onText;
        m_offText = offText;
    }

    void setChecked(bool checked)
    {
        m_toggleSwithEx->setChecked(checked);
    }

  public slots:
    void onThemeChanged();

  signals:
    void stateChanged(bool checked);

  protected:
    QString m_onText;
    QString m_offText;

    QHBoxLayout*       m_hMainLayout;
    FluToggleSwitchEx* m_toggleSwithEx;
    FluLabel*          m_textLabel;
};
