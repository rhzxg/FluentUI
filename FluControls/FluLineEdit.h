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
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluLineEdit.qss", this);
    }
};
