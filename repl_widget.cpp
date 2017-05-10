#include "repl_widget.hpp"
#include "message_widget.hpp"

REPLWidget::REPLWidget (QWidget * parent) : QWidget (parent) {
  repl_box = new QLineEdit();

  QBoxLayout *layout = new QHBoxLayout;
  QLabel *vtscript = new QLabel("vtscript>");

  layout->addWidget(vtscript);
  layout->addWidget(repl_box);
  this->setLayout(layout);

  connect(repl_box, &QLineEdit::returnPressed, this, &REPLWidget::enterPressed);


}

void REPLWidget::enterPressed() {

    QString repl_input = repl_box->text();

    emit lineEntered(repl_input);
    repl_box->clear();

}


REPLWidget::~REPLWidget() {
  this->close();
}
