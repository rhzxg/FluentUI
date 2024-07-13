#pragma once

#include <QLabel>
#include "../FluUtils/FluUtils.h"

class FluColorLabel : public QLabel
{
    Q_OBJECT
  public:
    FluColorLabel(QWidget* parent = nullptr) : QLabel(parent)
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluColorLabel.qss", this);
    }
};
