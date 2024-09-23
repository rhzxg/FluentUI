#pragma once

#include "FluWidget.h"
#include "../FluUtils/FluUtils.h"
#include <QPaintEvent>
#include <QPainter>
#include <QStyleOption>
#include <vector>

class FluTriangle : public FluWidget
{
    Q_OBJECT
  public:
    enum class FluTriangleOrient
    {
        Top,
        Bottom,
        Left,
        Right,
    };

  public:
    FluTriangle(QWidget* parent = nullptr);

    QList<QPoint> getPointsByOrient(FluTriangleOrient orient);

    void paintEvent(QPaintEvent* event);
  public slots:
    void onThemeChanged()
    {
        // if (FluThemeUtils::isLightTheme())
        //{
        //     FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluTriangle.qss", this);
        // }
        // else
        //{
        //     FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluTriangle.qss", this);
        // }
    }
};
