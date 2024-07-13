#pragma once

#include <QPaintEvent>
#include <QPainter>
#include <QPushButton>

#include "../FluUtils/FluUtils.h"

class FluPushButton : public QPushButton
{
    Q_OBJECT
  public:
    FluPushButton(QWidget *parent = nullptr) : QPushButton(parent)
    {
        setMinimumHeight(20);
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluPushButton.qss", this);
        if (FluThemeUtils::getUtils()->getTheme() == FluTheme::Dark)
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluPushButton.qss", this);
        }
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
    }
  public slots:
    void onThemeChanged()
    {
        if (FluThemeUtils::getUtils()->getTheme() == FluTheme::Light)
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluPushButton.qss", this);
        }
        else
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluPushButton.qss", this);
        }
    }

  protected:
};