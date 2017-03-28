#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include <iostream>
#include <cstring>
#include <tuple>

using namespace std;


enum Type {
    NoneType = 0,
    BooleanType,
    NumberType,
    SymbolType
};

struct point {
    double x;
    double y;
};

struct line {
    point one;
    point two;
};

struct arc {
    point p;
    line l;
};

typedef struct {
    double number_value;
    bool boolean_value;
    string string_value;
    point point_value;
    line line_value;
    arc arc_value;
} data;


typedef struct {
    Type type;
    data Data;
} Express;

class Expression {

public:
    Expression();
    Expression(bool value);
    Expression(double value);
    Expression(const std::string & value);


    Expression(std::tuple<double,double> value);

    // Construct an Expression with a single Line atom with starting
    // point start and ending point end
    Expression(std::tuple<double,double> start,
               std::tuple<double,double> end);

    // Construct an Expression with a single Arc atom with center
    // point center, starting point start, and spanning angle angle in radians
    Expression(std::tuple<double,double> center,
               std::tuple<double,double> start,
               double angle);

    bool operator==(const Expression & exp) const noexcept;	//TODO

    data Data;
    Express express;

private:


};




#endif
