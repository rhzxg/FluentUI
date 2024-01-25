#include "FluMenu.h"
#include "FluDef.h"
#include "../FluUtils/FluIconUtils.h"
#include <QGraphicsDropShadowEffect>
#include "../FluUtils/FluUtils.h"
#include <QPainterPath>
#include <QPainter>
#include <QStyleOption>
#include <QWidgetAction>
#include <QMoveEvent>
//#include "../FluControls/FluMenuIconTextItem.h"
//#include "FluMenuIconTextAction.h"


FluMenu::FluMenu(QWidget* parent /*= nullptr*/) : QMenu(parent)
{
    setWindowFlags(windowFlags() | Qt::NoDropShadowWindowHint | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground, true);
    setMouseTracking(true);
    FluStyleSheetUitls::setQssByFileName("../StyleSheet/light/FluMenu.qss", this);
}

void FluMenu::addAction(QAction* action)
{
    QMenu::addAction(action);
    connect(action, &QAction::hovered, [=]() { LOG_DEBUG << "hovered"; });

    // connect(action, &QAction::ho, [=]() {
    //     LOG_DEBUG << "trigger";
    //     });
}

void FluMenu::mouseMoveEvent(QMouseEvent* e)
{
    QMenu::mouseMoveEvent(e);
    // hit action
   // QAction* action = actionAt(e->position().toPoint());
   // if (!action)
   // {
   //     return;
   // }

   // FluMenuIconTextAction* defaultAction = (FluMenuIconTextAction*)action;
   // if (action == nullptr)
   //     return;

   // auto defaultWidget = (FluMenuIconTextItem*)defaultAction->defaultWidget();
   // if (defaultWidget == nullptr)
   //     return;

   //LOG_DEBUG << defaultWidget->getTextLabel()->text();
   //// has sub menu display.
   // if (defaultAction == nullptr)
   //     return;
   // 
   // auto innerMenu = defaultAction->getInnerMenu();
   // if (innerMenu == nullptr)
   //     return;

   // QPoint gPoint = QPoint(defaultWidget->x() + defaultWidget->width(), defaultWidget->y());
   // gPoint = mapToGlobal(gPoint);
  //  innerMenu->exec(gPoint);
}

void FluMenu::paintEvent(QPaintEvent* event)
{
    QMenu::paintEvent(event);
  //  QStyleOption opt;
  //  opt.initFrom(this);
  //  QPainter painter(this);
  //  style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}