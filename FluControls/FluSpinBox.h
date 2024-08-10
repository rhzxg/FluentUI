#pragma once

#include "../FluUtils/FluUtils.h"
#include <QSpinBox>

class FluSpinBox : public QSpinBox
{
    Q_OBJECT
  public:
    FluSpinBox(QWidget* parent = nullptr) : QSpinBox(parent)
    {
        onThemeChanged();
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
    }

    void paintEvent(QPaintEvent* event)
    {
        QSpinBox::paintEvent(event);
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
            FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluSpinBox.qss", this);
        }
        else
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluSpinBox.qss", this);
        }
    }
};
