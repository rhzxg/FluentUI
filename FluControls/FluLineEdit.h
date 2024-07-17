#pragma once

#include <QLineEdit>
#include "FluDef.h"
#include "../FluUtils/FluUtils.h"

class FluLineEdit : public QLineEdit
{
    Q_OBJECT
  public:
    FluLineEdit(QWidget* parent = nullptr) : QLineEdit(parent)
    {
        onThemeChanged();
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
    }

  public slots:
    virtual void onThemeChanged()
    {
        if (FluThemeUtils::isLightTheme())
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluLineEdit.qss", this);
        }
        else
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluLineEdit.qss", this);
        }
    }
};
