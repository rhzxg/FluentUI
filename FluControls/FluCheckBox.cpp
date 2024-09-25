#include "FluCheckBox.h"

FluCheckBox::FluCheckBox(QWidget* parent /*= nullptr*/) : QCheckBox(parent)
{
    FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluCheckBox.qss", this);
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
}

FluCheckBox::FluCheckBox(const QString& text, QWidget* parent /*= nullptr*/) : QCheckBox(text, parent)
{
    FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluCheckBox.qss", this);
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
}

void FluCheckBox::onThemeChanged()
{
    if (FluThemeUtils::isLightTheme())
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluCheckBox.qss", this);
    }
    else
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluCheckBox.qss", this);
    }
}
