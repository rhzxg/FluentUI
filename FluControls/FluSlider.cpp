#include "FluSlider.h"

FluSlider::FluSlider(QWidget* parent /*= nullptr*/) : QSlider(parent)
{
    FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluSlider.qss", this);
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
}

FluSlider::FluSlider(Qt::Orientation orientation, QWidget* parent /*= nullptr*/) : QSlider(orientation, parent)
{
    FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluSlider.qss", this);
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
}

void FluSlider::onThemeChanged()
{
    if (FluThemeUtils::isLightTheme())
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluSlider.qss", this);
    }
    else
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluSlider.qss", this);
    }
}
