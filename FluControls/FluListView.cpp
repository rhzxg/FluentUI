#include "FluListView.h"

FluListView::FluListView(QWidget* parent /*= nullptr*/) : QListWidget(parent)
{
    setItemDelegate(new FluListViewItemDelegate);
    FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluListView.qss", this);
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
}

void FluListView::onThemeChanged()
{
    if (FluThemeUtils::isLightTheme())
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluListView.qss", this);
        //  style()->polish(this);
        //    setItemDelegate(new FluListViewItemDelegate);
    }
    else
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluListView.qss", this);
        //  style()->polish(this);
        //  setItemDelegate(new FluListViewItemDelegate);
    }
}
