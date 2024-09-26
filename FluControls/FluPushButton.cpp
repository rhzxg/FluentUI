#include "FluPushButton.h"

FluPushButton::FluPushButton(QWidget *parent /*= nullptr*/) : QPushButton(parent)
{
    // setFixedSize(200, 30);
    setMinimumHeight(20);
    FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluPushButton.qss", this);
    if (FluThemeUtils::isDarkTheme())
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluPushButton.qss", this);
    }
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
}

FluPushButton::FluPushButton(const QString &text, QWidget *parent /*= nullptr*/) : FluPushButton(parent)
{
    setText(text);
}

void FluPushButton::onThemeChanged()
{
    if (FluThemeUtils::isLightTheme())
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluPushButton.qss", this);
    }
    else
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluPushButton.qss", this);
    }
}
