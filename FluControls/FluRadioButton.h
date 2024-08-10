#pragma once

#include <QRadioButton>
#include "../FluUtils/FluUtils.h"
#include <QProxyStyle>
#include <QPainter>
#include <QStyleOptionButton>

class FluRadioButton : public QRadioButton
{
    Q_OBJECT
  public:
    explicit FluRadioButton(QWidget* parent = nullptr) : QRadioButton(parent)
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluRadioButton.qss", this);
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
    }

    explicit FluRadioButton(const QString& text, QWidget* parent = nullptr) : QRadioButton(text, parent)
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluRadioButton.qss", this);
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
    }

  public slots:
    void onThemeChanged()
    {
        if (FluThemeUtils::isLightTheme())
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluRadioButton.qss", this);
        }
        else
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluRadioButton.qss", this);
        }
    }
};
