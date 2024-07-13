#pragma once

#include <QCheckBox>
#include "../FluUtils/FluUtils.h"

class FluCheckBox : public QCheckBox
{
    Q_OBJECT
  public:
    explicit FluCheckBox(QWidget* parent = nullptr) : QCheckBox(parent)
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluCheckBox.qss", this);
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
    }

    explicit FluCheckBox(const QString& text, QWidget* parent = nullptr) : QCheckBox(text, parent)
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluCheckBox.qss", this);
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
    }

  public slots:
    void onThemeChanged()
    {
        if (FluThemeUtils::getUtils()->getTheme() == FluTheme::Light)
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluCheckBox.qss", this);
        }
        else
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluCheckBox.qss", this);
        }
    }
};
