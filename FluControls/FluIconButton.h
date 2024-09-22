
#pragma once

#include <QPushButton>
#include "FluDef.h"
#include "../FluUtils/FluUtils.h"
#include <QTimer>
#include <QStyle>

// to display fluent icon use fluent font
class FluIconButton : public QPushButton
{
    Q_OBJECT
  public:
    FluIconButton(QWidget* parent = nullptr) : QPushButton(parent), m_type1(FluAwesomeType::None), m_type2(FluAwesomeType::None), m_type(FluAwesomeType::None)
    {
        // set fixed size
        setFixedSize(30, 30);
        setIconSize(QSize(20, 20));
        setNoBorder(false);

        // FluStyleSheetUitls::setQssByFileName("../StyleSheet/light/FluIconButton.qss", this);
        onThemeChanged();
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
    }

    FluIconButton(FluAwesomeType type1, QWidget* parent = nullptr)
        : QPushButton(parent)
    {
        setFixedSize(30, 30);
        setIconSize(QSize(20, 20));
        setNoBorder(false);

        // please ensure type1 will in FluAwesomeType, if can't suitable may crash.

        m_type1 = type1;
        setType(type1);
        // FluStyleSheetUitls::setQssByFileName("../StyleSheet/light/FluIconButton.qss", this);
        onThemeChanged();
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
    }

    FluIconButton(FluAwesomeType type1, FluAwesomeType type2, QWidget* parent = nullptr) : QPushButton(parent), m_type1(type1), m_type2(type2), m_type(FluAwesomeType::None)
    {
        setFixedSize(30, 30);
        setIconSize(QSize(20, 20));
        setNoBorder(false);

        // please ensure type1 will in FluAwesomeType, if can't suitable may crash.

        QPixmap pixmap = FluIconUtils::getFluentIconPixmap(type1, m_penColor);
        pixmap         = pixmap.scaled(20, 20, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        setIcon(QIcon(pixmap));

        // FluStyleSheetUitls::setQssByFileName("../StyleSheet/light/FluIconButton.qss", this);
        onThemeChanged();

        // can change type1 to type2, type2 auto change to type1
        m_timer = new QTimer;
        m_timer->setInterval(500);
        connect(m_timer, &QTimer::timeout, [=]() {
            // change type2 to type1
            setType(m_type1);
        });

        connect(this, &FluIconButton::clicked, [=](bool b) {
            // change to type2
            setType(m_type2);
            m_timer->start();
        });
        connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
    }

    void setType(FluAwesomeType type)
    {
        m_type         = type;
        QPixmap pixmap = FluIconUtils::getFluentIconPixmap(type, m_penColor);
        pixmap         = pixmap.scaled(20, 20, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        setIcon(QIcon(pixmap));
    }

    void setType1(FluAwesomeType type)
    {
        m_type1 = type;
        setType(m_type1);
    }

    void setType2(FluAwesomeType type)
    {
        m_type2 = type;
        setType(m_type2);
    }

    void setNoBorder(bool bNoBorder)
    {
        setProperty("noBorder", bNoBorder);
        style()->polish(this);
    }

  public slots:
    void onThemeChanged()
    {
        if (FluThemeUtils::isLightTheme())
        {
            m_penColor = QColor(8, 8, 8);
            FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluIconButton.qss", this);
            setType(m_type);
        }
        else
        {
            m_penColor = QColor(239, 239, 239);
            FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluIconButton.qss", this);
            setType(m_type);
        }
    }

  protected:
    FluAwesomeType m_type;
    FluAwesomeType m_type1;
    FluAwesomeType m_type2;
    QColor         m_penColor;

    QTimer* m_timer;
    bool    m_bClicked;
};
