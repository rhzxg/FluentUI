#include "FluStyleButton.h"

FluStyleButton::FluStyleButton(QWidget* parent /*= nullptr*/) : QPushButton(parent)
{
    setFixedSize(200, 30);
    onThemeChanged();
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
}

void FluStyleButton::onThemeChanged()
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
