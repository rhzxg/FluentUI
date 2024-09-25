#include "FluTabWidget.h"

FluTabWidget::FluTabWidget(QWidget *parent /*= nullptr*/) : QTabWidget(parent)
{
    QString qss = FluStyleSheetUitls::getQssByFileName("/resources/qss/light/FluTabWidget.qss");
    setStyleSheet(qss);
}
