#include "FluGraphicalButton.h"

FluGraphicalButton::FluGraphicalButton(QWidget* parent /*= nullptr*/) : QPushButton(parent)
{
    setFixedSize(50, 50);
    setIconSize(QSize(28, 28));
    // FluStyleSheetUitls::setQssByFileName("../StyleSheet/light/FluGraphicalButton.qss", this);

    onThemeChanged();
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
}

void FluGraphicalButton::onThemeChanged()
{
    if (FluThemeUtils::isLightTheme())
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluGraphicalButton.qss", this);
    }
    else
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluGraphicalButton.qss", this);
    }
}
