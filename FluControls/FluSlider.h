#pragma once

#include <QSlider>

#include "../FluUtils/FluUtils.h"

class FluSlider : public QSlider
{
    Q_OBJECT
  public:
    FluSlider(QWidget* parent = nullptr) : QSlider(parent)
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluSlider.qss", this);
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
    }

    FluSlider(Qt::Orientation orientation, QWidget* parent = nullptr) : QSlider(orientation, parent)
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluSlider.qss", this);
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
    }

  public slots:
    void onThemeChanged()
    {
        if (FluThemeUtils::getUtils()->getTheme() == FluTheme::Light)
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluSlider.qss", this);
        }
        else
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluSlider.qss", this);
        }
    }
};
