#include "FluSpinBox.h"

FluSpinBox::FluSpinBox(QWidget* parent /*= nullptr*/) : QSpinBox(parent)
{
    onThemeChanged();
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
}

void FluSpinBox::paintEvent(QPaintEvent* event)
{
    QSpinBox::paintEvent(event);
    if (!hasFocus())
        return;

    QPainter painter(this);
    FluStyleSheetUitls::drawBottomLineIndicator(this, &painter);
}

void FluSpinBox::onThemeChanged()
{
    if (FluThemeUtils::isLightTheme())
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluSpinBox.qss", this);
    }
    else
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluSpinBox.qss", this);
    }
}
