#pragma once

#include <QMenuBar>
#include "../FluUtils/FluUtils.h"
#include <QPainter>
#include <QStyleOption>
#include <QHBoxLayout>
#include <QVBoxLayout>

class FluMenuBar : public QMenuBar
{
    Q_OBJECT
  public:
    FluMenuBar(QWidget* parent = nullptr) : QMenuBar(parent)
    {
        setMouseTracking(true);
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluMenuBar.qss", this);
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
    }

  public slots:
    void onThemeChanged()
    {
        if (FluThemeUtils::isLightTheme())
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluMenuBar.qss", this);
        }
        else
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluMenuBar.qss", this);
        }
    }
};
