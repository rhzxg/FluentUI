#pragma once

#include "FluVScrollView.h"
#include "../FluUtils/FluUtils.h"
#include <QVBoxLayout>
#include <QListWidget>
#include "FluListViewItemDelegate.h"

class FluListView : public QListWidget
{
    Q_OBJECT
  public:
    FluListView(QWidget* parent = nullptr) : QListWidget(parent)
    {
        setItemDelegate(new FluListViewItemDelegate);
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluListView.qss", this);
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
    }

  public slots:
    void onThemeChanged()
    {
        if (FluThemeUtils::getUtils()->getTheme() == FluTheme::Light)
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
};
