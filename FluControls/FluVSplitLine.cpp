#include "FluVSplitLine.h"

FluVSplitLine::FluVSplitLine(QWidget* parent /*= nullptr*/) : FluWidget(parent)
{
    setFixedHeight(1);
    // FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluVSplitLine.qss", this);
    onThemeChanged();
}

void FluVSplitLine::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}

void FluVSplitLine::onThemeChanged()
{
    if (FluThemeUtils::isLightTheme())
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluVSplitLine.qss", this);
    }
    else
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluVSplitLine.qss", this);
    }
}
