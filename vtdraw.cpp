#include <QCoreApplication>
#include <QApplication>

#include "main_window.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "interpreter.hpp"
#include "environment.hpp"
#include "interpreter_semantic_error.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    window.show();
    return a.exec();
}
