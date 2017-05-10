#include "message_widget.hpp"
#include "repl_widget.hpp"
#include "qt_interpreter.hpp"
#include <QLineEdit>
#include <QKeyEvent>
#include <QString>
#include <QLayout>



MessageWidget::MessageWidget (QWidget * parent) : QWidget (parent) {

  message_box = new QLineEdit();

  QBoxLayout *horizontal_layout = new QHBoxLayout;
  QLabel *message = new QLabel("Message:");

  horizontal_layout->addWidget(message);
  horizontal_layout->addWidget(message_box);
  this->setLayout(horizontal_layout);

  message_box->setReadOnly(true);



}

void MessageWidget::error(QString message) {

  QPalette *palette = new QPalette();

  palette->setColor(QPalette::Highlight,Qt::red);
  palette->setColor(QPalette::Text,Qt::black);

  message_box->setPalette(*palette);

  message_box->setText(message);

  message_box->selectAll();

}

void MessageWidget::info(QString message) {

  QPalette *palette = new QPalette();

  palette->setColor(QPalette::Text,Qt::black);
  message_box->setPalette(*palette);

  message_box->setText(message);

}
