#pragma once

#include <QDoubleSpinBox>
#include "../FluUtils/FluUtils.h"

class FluDoubleSpinBox : public QDoubleSpinBox
{
    Q_OBJECT
  public:
    FluDoubleSpinBox(QWidget* parent = nullptr) : QDoubleSpinBox(parent)
    {
        onThemeChanged();
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
    }

    void paintEvent(QPaintEvent* event)
    {
        QDoubleSpinBox::paintEvent(event);
        if (!hasFocus())
            return;

        QPainter painter(this);
        FluStyleSheetUitls::drawBottomLineIndicator(this, &painter);
    }

  public slots:
    void onThemeChanged()
    {
        if (FluThemeUtils::isLightTheme())
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluDoubleSpinBox.qss", this);
        }
        else
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluDoubleSpinBox.qss", this);
        }
    }
};
