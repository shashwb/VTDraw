#include "repl_widget.hpp"

// Default construct a REPLWidget
REPLWidget::REPLWidget(QWidget * parent) : QWidget(parent) {

    replLabel = new QLabel;
    replLabel->setText("vtscript>");
    replBox = new QLineEdit;

}


// A signal that sends the current edited text as a QString when the return key is pressed.
void REPLWidget::lineEntered(QString) {

}
