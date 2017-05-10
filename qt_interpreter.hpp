#ifndef QT_INTERPRETER_HPP
#define QT_INTERPRETER_HPP
#include "interpreter.hpp"
#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsItem>
#include <iostream>
#include <QLineEdit>
#include <QString>
#include <QObject>
#include <QEvent>
#include <QObject>
#include <vector>



class QtInterpreter : public QObject {
    Q_OBJECT

public:
    QtInterpreter(QObject * parent = nullptr);

signals:
    void drawGraphic(QGraphicsItem * item);
    void info(QString message);
    void error(QString message);

public slots:
    void parseAndEvaluate(QString entry);
    void determineMessageOutput(Expression exp);
    void recieveDrawVector();

private:

    Interpreter inter;
    vector<Expression *> qtDrawVector;

};

#endif
