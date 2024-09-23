#include "FluMenuBar.h"

FluMenuBar::FluMenuBar(QWidget* parent /*= nullptr*/) : QMenuBar(parent)
{
    setMouseTracking(true);
    FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluMenuBar.qss", this);
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
}

void FluMenuBar::onThemeChanged()
{
    if (FluThemeUtils::isLightTheme())
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluMenuBar.qss", this);
    }
    else
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluMenuBar.qss", this);
    }
}
