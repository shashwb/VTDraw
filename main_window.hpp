#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

// #include <QGraphicsItem>
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QVBoxLayout>


class MainWindow : public QWidget
{


    Q_OBJECT


public:
  // Default construct a MainWindow
  MainWindow(QWidget * parent = nullptr);

// Default construct a MainWidow, using filename as the script file to attempt to preload
  MainWindow(std::string filename, QWidget * parent = nullptr);
};

#endif // REPL_WIDGET_H
