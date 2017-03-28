#include "message_widget.hpp"


MessageWidget::MessageWidget(QWidget * parent) : QWidget(parent) {

    messageLabel = new QLabel;
    messageLabel->setText("Message:");
    messageBox = new QLineEdit;
    messageBox->setReadOnly(true);

}

// a public slot accepting an informational message to display, clearing any error formatting
void MessageWidget::info(QString message) {

}

// a public slot accepting an error message to display as selected text highlighted with a red background.
void MessageWidget::error(QString message) {

}
