#include "main_window.hpp"
#include "message_widget.hpp"
#include "canvas_widget.hpp"
#include "qt_interpreter.hpp"
#include "repl_widget.hpp"


MainWindow::MainWindow(QWidget * parent) : QWidget(parent) {
    
    QBoxLayout *main_layout = new QVBoxLayout;
    QtInterpreter *interpreter_gui = new QtInterpreter(this);
    MessageWidget *message = new MessageWidget(this);
    main_layout->addWidget(message);
    CanvasWidget *canvas = new CanvasWidget(this);
    main_layout->addWidget(canvas);
    REPLWidget *repl = new REPLWidget(this);
    main_layout->addWidget(repl);
    this->setLayout(main_layout);
    this->setMinimumSize(800, 600);
    connect(repl, &REPLWidget::lineEntered, interpreter_gui, &QtInterpreter::parseAndEvaluate);
    connect(interpreter_gui, &QtInterpreter::info, message, &MessageWidget::info);
    connect(interpreter_gui, &QtInterpreter::error, message, &MessageWidget::error);
    connect(interpreter_gui, &QtInterpreter::drawGraphic, canvas, &CanvasWidget::addGraphic);
    
}

MainWindow::MainWindow(std::string filename, QWidget * parent) : QWidget(parent) {

}
