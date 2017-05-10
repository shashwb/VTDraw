#ifndef MESSAGE_WIDGET_HPP
#define MESSAGE_WIDGET_HPP

#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QBoxLayout>
#include <QObject>
#include <QLabel>
#include <QEvent>
#include <QDebug>

class MessageWidget: public QWidget {
    Q_OBJECT
public:
    QLineEdit *message_box;
    // Default construct a MessageWidget displaying no text
    MessageWidget(QWidget * parent = nullptr);

private:

    //QLineEdit *mbox;


public slots:
    // a public slot accepting an informational message to display, clearing any error formatting
    void info(QString message);

    // a public slot accepting an error message to display as selected text highlighted with a red background.
    void error(QString message);


};

#endif
