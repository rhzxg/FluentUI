#pragma once

#include <QPushButton>
#include "../FluUtils/FluUtils.h"
#include <QDesktopServices>

class FluHyperLinkButton : public QPushButton
{
    Q_OBJECT
  public:
    FluHyperLinkButton(QString linkUrl, QWidget* parent = nullptr);

    void setLinkUrl(QString linkUrl)
    {
        m_linkUrl = linkUrl;
    }

  public slots:
    void onThemeChanged()
    {
        if (FluThemeUtils::isLightTheme())
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluHyperLinkButton.qss", this);
        }
        else
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluHyperLinkButton.qss", this);
        }
    }

  protected:
    QString m_linkUrl;
};
