#ifndef MESSAGE_WIDGET_H
#define MESSAGE_WIDGET_H

// #include "message_widget.hpp"

// #include <QGraphicsItem>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>

class MessageWidget : public QWidget
{

    Q_OBJECT


public:
  // Default construct a MessageWidget displaying no text
  MessageWidget(QWidget * parent = nullptr);

  // a public slot accepting an informational message to display, clearing any error formatting
  void info(QString message);

  // a public slot accepting an error message to display as selected text highlighted with a red background.
  void error(QString message);


   QLineEdit *messageBox;
   QLabel *messageLabel;

};

#endif // REPL_WIDGET_H
