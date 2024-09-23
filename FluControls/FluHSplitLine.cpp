#include "FluHSplitLine.h"

FluHSplitLine::FluHSplitLine(QWidget* parent /*= nullptr*/) : FluWidget(parent)
{
    setFixedWidth(1);
    // FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluHSplitLine.qss", this);
    onThemeChanged();
}

void FluHSplitLine::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}

void FluHSplitLine::onThemeChanged()
{
    if (FluThemeUtils::isLightTheme())
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluHSplitLine.qss", this);
    }
    else
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluHSplitLine.qss", this);
    }
}
