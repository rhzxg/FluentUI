#include "FluHRadioGroupBox.h"

FluHRadioGroupBox::FluHRadioGroupBox(QWidget* parent /*= nullptr*/) : QGroupBox(parent)
{
    m_hMainLayout = new QVBoxLayout;
    // m_vMainLayout->setContentsMargins(0,0,0,0);

    setLayout(m_hMainLayout);
    m_hMainLayout->addSpacing(15);
    FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluVRadioGroupBox.qss", this);
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
}

FluHRadioGroupBox::FluHRadioGroupBox(QString title, QWidget* parent /*= nullptr*/) : QGroupBox(title, parent)
{
    m_hMainLayout = new QVBoxLayout;
    // m_vMainLayout->setContentsMargins(5, 5, 5, 5);
    // m_vMainLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(m_hMainLayout);
    m_hMainLayout->addSpacing(15);
    FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluVRadioGroupBox.qss", this);
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
}

void FluHRadioGroupBox::addRadioButton(FluRadioButton* radioButton)
{
    m_hMainLayout->addWidget(radioButton);
}

void FluHRadioGroupBox::onThemeChanged()
{
    if (FluThemeUtils::isLightTheme())
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluVRadioGroupBox.qss", this);
    }
    else
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluVRadioGroupBox.qss", this);
    }
}
