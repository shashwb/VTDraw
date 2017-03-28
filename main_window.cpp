#include "main_window.hpp"
#include "message_widget.hpp"
#include "repl_widget.hpp"
#include "canvas_widget.hpp"

// Default construct a MainWindow
MainWindow::MainWindow(QWidget * parent) {


    QWidget *window = new QWidget;

    //constructors for necessary objects
    MessageWidget message_widget;
    REPLWidget repl_widget;
    CanvasWidget canvas_widget;

    QHBoxLayout *messageLayout = new QHBoxLayout;
    messageLayout->addWidget(message_widget.messageLabel);
    messageLayout->addWidget(message_widget.messageBox);

    QVBoxLayout *overall_layout = new QVBoxLayout;
    overall_layout->addLayout(messageLayout);


    QHBoxLayout *replLayout = new QHBoxLayout;
    replLayout->addWidget(repl_widget.replLabel);
    replLayout->addWidget(repl_widget.replBox);

    overall_layout->addWidget(canvas_widget.canvasBox);

    overall_layout->addLayout(replLayout);

    window->setLayout(overall_layout);
    window->show();


}

// Default construct a MainWidow, using filename as the script file to attempt to preload
MainWindow::MainWindow(std::string filename, QWidget * parent) {

}
