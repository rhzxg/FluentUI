#include "FluComboBox.h"

FluComboBox::FluComboBox(QWidget* parent /*= nullptr*/) : QComboBox(parent)
{
    // setFixedHeight(30);
    setEditable(false);
    setView(new QListView());
    view()->window()->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
    view()->window()->setAttribute(Qt::WA_TranslucentBackground);
    FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluComboBox.qss", this);
}

void FluComboBox::onThemeChanged()
{
    if (FluThemeUtils::isLightTheme())
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluComboBox.qss", this);
    }
    else
    {
        FluStyleSheetUitls::setQssByFileName("/resources/qss/dark/FluComboBox.qss", this);
    }
}
