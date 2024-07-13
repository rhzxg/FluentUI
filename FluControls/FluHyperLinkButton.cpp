#include "FluHyperLinkButton.h"

FluHyperLinkButton::FluHyperLinkButton(QString linkUrl, QWidget* parent /* = nullptr*/) : QPushButton(parent), m_linkUrl(linkUrl)
{
    connect(this, &FluHyperLinkButton::clicked, [=](bool bClicked) { QDesktopServices::openUrl(QUrl(m_linkUrl)); });
    FluStyleSheetUitls::setQssByFileName("/resources/qss/light/FluHyperLinkButton.qss", this);
    onThemeChanged();
    connect(FluThemeUtils::getUtils(), &FluThemeUtils::themeChanged, this, [=](FluTheme theme) { onThemeChanged(); });
}
