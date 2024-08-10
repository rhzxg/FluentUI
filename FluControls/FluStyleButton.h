#pragma once

#include "../FluUtils/FluUtils.h"
#include <QPushButton>

class FluStyleButton : public QPushButton
{
    Q_OBJECT
  public:
    FluStyleButton(QWidget* parent = nullptr) : QPushButton(parent)
    {
        setFixedSize(200, 30);
        onThemeChanged();
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, [=](FluTheme theme) { onThemeChanged(); });
    }

  public slots:
    void onThemeChanged()
    {
        if (FluThemeUtils::isLightTheme())
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluStyleButton.qss", this);
        }
        else
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluStyleButton.qss", this);
        }
    }
};
