#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QWidget>
#include <QtGui>
#include <QApplication>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QObject>
#include <QEvent>
#include <QLabel>


class MainWindow: public QWidget {
    Q_OBJECT
public:
    // Default construct a MainWindow
    MainWindow(QWidget * parent = nullptr);

    // Default construct a MainWindow, using filename as the script file to attempt to preload
    MainWindow(std::string filename, QWidget * parent = nullptr);

};


#endif
