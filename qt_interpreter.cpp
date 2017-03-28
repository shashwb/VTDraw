#include "qt_interpreter.hpp"
//#include "interpreter.h"
#include <QObject>

// Default construct an QtInterpreter with the default environment and an empty AST
QtInterpreter::QtInterpreter(QObject * parent) : QObject(parent) {

}

//// a signal emitting a graphic to be drawn as a pointer
//void QtInterpreter::drawGraphic(QGraphicsItem * item) {

//}

//// a signal emitting an informational message
//void QtInterpreter::info(QString message) {

//}

//// a signal emitting an error message
//void QtInterpreter::error(QString message) {

//}

//// a public slot that accepts and expression string and parses/evaluates it
//void QtInterpreter::parseAndEvaluate(QString entry) {

//}
