#pragma once

#include "FluWidget.h"
#include <QStyleOption>
#include <QPainter>
#include "../FluUtils/FluUtils.h"

class FluVSplitLine : public FluWidget
{
    Q_OBJECT
  public:
    FluVSplitLine(QWidget* parent = nullptr) : FluWidget(parent)
    {
        setFixedHeight(1);
        // FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluVSplitLine.qss", this);
        onThemeChanged();
    }

    void paintEvent(QPaintEvent* event)
    {
        QStyleOption opt;
        opt.initFrom(this);
        QPainter painter(this);
        style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
    }
  public slots:
    void onThemeChanged()
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
};
