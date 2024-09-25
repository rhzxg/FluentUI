#include "FluVRadioGroupBox.h"

FluVRadioGroupBox::FluVRadioGroupBox(QWidget* parent /*= nullptr*/) : QGroupBox(parent)
{
    m_vMainLayout = new QVBoxLayout;
    // m_vMainLayout->setContentsMargins(0,0,0,0);

    setLayout(m_vMainLayout);
    m_vMainLayout->addSpacing(15);
    FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluVRadioGroupBox.qss", this);
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
}

FluVRadioGroupBox::FluVRadioGroupBox(QString title, QWidget* parent /*= nullptr*/) : QGroupBox(title, parent)
{
    m_vMainLayout = new QVBoxLayout;
    // m_vMainLayout->setContentsMargins(5, 5, 5, 5);
    // m_vMainLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(m_vMainLayout);
    m_vMainLayout->addSpacing(15);
    FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluVRadioGroupBox.qss", this);
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
}

void FluVRadioGroupBox::addRadioButton(FluRadioButton* radioButton)
{
    m_vMainLayout->addWidget(radioButton);
}

void FluVRadioGroupBox::onThemeChanged()
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
