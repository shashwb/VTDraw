#include "qt_interpreter.hpp"
#include "message_widget.hpp"
#include "interpreter_semantic_error.hpp"
#include "repl_widget.hpp"
#include "tokenize.hpp"
#include <fstream>
#include <sstream>
#include <QLineEdit>
#include <iostream>
#include <QPainter>

using namespace std;


QtInterpreter::QtInterpreter(QObject * parent) : QObject(parent) { }


void QtInterpreter::parseAndEvaluate(QString entry) {
    
    string parse = entry.toStdString();
    istringstream stream(parse);
    bool ifParsable = false;
    bool loop = false;
    Expression exp;
    
    ifParsable = inter.parse(stream);
    if (ifParsable) {
      try {
          exp = inter.eval();
          recieveDrawVector();  //gets the drawVector from the c++ interpreter
          determineMessageOutput(exp);
      }
      catch (InterpreterSemanticError(&e)) {
        QString string_input = QString::fromStdString(e.what());
        //error message
        emit error(string_input);
        loop = true;
      }
    }
    else {
        QString notParseableError = "Error: Cannot Parse This Doe";
        emit error(notParseableError);
    }
}


void QtInterpreter::determineMessageOutput(Expression exp) {
    
    QString result_str;
    QString result_bool;
    double result_num;
    QString paren = "(";
    if (qtDrawVector.size() >= 1) {
        emit info("(None)");
        for (int i = 0; i < qtDrawVector.size(); i++) {
            if (qtDrawVector[i]->express.type == NoneType) {
            }
            if (qtDrawVector[i]->express.type == PointType) {
                QGraphicsEllipseItem * pointItem = new QGraphicsEllipseItem(qreal(get<0>(qtDrawVector[i]->express.Data.point.point_value)),
                                                                            qreal(get<1>(qtDrawVector[i]->express.Data.point.point_value)), 2, 2);
                pointItem->setBrush(QBrush(Qt::black));
                emit drawGraphic(pointItem);
            }
            if (qtDrawVector[i]->express.type == LineType) {
                QGraphicsLineItem * lineItem = new QGraphicsLineItem(qreal(get<0>(qtDrawVector[i]->express.Data.Line.line_value_start.point_value)),
                                                                     qreal(get<1>(qtDrawVector[i]->express.Data.Line.line_value_start.point_value)),
                                                                     qreal(get<0>(qtDrawVector[i]->express.Data.Line.line_value_end.point_value)),
                                                                     qreal(get<1>(qtDrawVector[i]->express.Data.Line.line_value_end.point_value)));
                emit drawGraphic(lineItem);
            }
        }
    }
    if (exp.express.type == BooleanType) {
        if (exp.express.Data.boolean_value == 0) {
            emit info("(False)");
        }
        else {
            emit info ("(True)");
        }
    }
    if (exp.express.type == NumberType) {
        result_num = exp.express.Data.number_value;
        QString result_num_str = QString::number(result_num);
        paren.append(result_num_str);
        paren.append(")");
        emit info(paren);
    }
    if (exp.express.type == SymbolType) {
        result_str = QString::fromStdString(exp.express.Data.string_value);
        paren.append(result_str);
        paren.append(")");
        if (exp.express.Data.string_value == "foo") {
            emit error("Error");
        }
    }
    if (exp.express.type == PointType) {
        string first_str = to_string(get<0>(exp.express.Data.point.point_value));
        string second_str = to_string(get<1>(exp.express.Data.point.point_value));
        if (first_str[first_str.size()-1] == '.') {
            first_str.erase(first_str.end()-1);
        }
        if (second_str[second_str.size()-1] == '.') {
            second_str.erase(second_str.end()-1);
        }
//        cout << "first: " << first_str << endl;
//        cout << "second: " << second_str << endl;
        QString first = QString::fromStdString(first_str);
        QString second = QString::fromStdString(second_str);
        paren.append(first);
        paren.append(",");
        paren.append(second);
        paren.append(")");
        emit info(paren);
    }
    if (exp.express.type == LineType) {
        //need to emit the info!
        string first_str_one = to_string(get<0>(exp.express.Data.Line.line_value_start.point_value));
        string first_str_two = to_string(get<1>(exp.express.Data.Line.line_value_start.point_value));
        string second_str_one = to_string(get<0>(exp.express.Data.Line.line_value_end.point_value));
        string second_str_two = to_string(get<1>(exp.express.Data.Line.line_value_end.point_value));
        QString first_one = QString::fromStdString(first_str_one);
        QString first_two = QString::fromStdString(first_str_two);
        QString second_one = QString::fromStdString(second_str_one);
        QString second_two = QString::fromStdString(second_str_two);
        paren.append(first_one).append(",").append(first_two).append("),").append("(").append(second_one).append(",").append(second_two).append(")");
        emit info(paren);
    }
}



void QtInterpreter::recieveDrawVector() {
    qtDrawVector = inter.drawVectorGetter();
//    cout << "Size of the QtDrawVector: " << qtDrawVector.size() << endl;
}






