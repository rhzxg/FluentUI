#pragma once

#include "FluWidget.h"
#include <QScrollArea>
#include "FluFlowLayout.h"
#include "../FluUtils/FluUtils.h"

class FluFWScrollView : public QScrollArea
{
    Q_OBJECT
  public:
    FluFWScrollView(QWidget* parent = nullptr) : QScrollArea(parent)
    {
        setWidgetResizable(true);
        setMinimumSize(0, 0);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_contextWidget = new QWidget(this);
        setWidget(m_contextWidget);
        m_vMainLayout = new FluFlowLayout(m_contextWidget);
        m_contextWidget->setObjectName("contextWidget");
        QString qss = FluStyleSheetUitls::getQssByFileName("/resources/qss/light/FluFWScrollView.qss");
        setStyleSheet(qss);
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
    }

    FluFlowLayout* getMainLayout()
    {
        return m_vMainLayout;
    }
  public slots:
    void onThemeChanged()
    {
        if (FluThemeUtils::isLightTheme())
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluFWScrollView.qss", this);
        }
        else
        {
            FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluFWScrollView.qss", this);
        }
    }

  protected:
    QWidget* m_contextWidget;
    FluFlowLayout* m_vMainLayout;
};
