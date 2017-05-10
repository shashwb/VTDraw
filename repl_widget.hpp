#ifndef REPL_WIDGET_HPP
#define REPL_WIDGET_HPP

#include <QWidget>
#include <QLineEdit>
#include <QString>
#include <QObject>
#include <QEvent>
#include <QBoxLayout>
#include <QLabel>
#include <QKeyEvent>
#include <QDebug>
#include <iostream>

class REPLWidget: public QWidget {
    Q_OBJECT


public:
    // Default construct a REPLWidget
    REPLWidget(QWidget * parent = nullptr);
    ~REPLWidget();


    //public member
    QLineEdit *repl_box;

public slots:
    void enterPressed();


signals:
    void lineEntered(QString);



};


#endif
