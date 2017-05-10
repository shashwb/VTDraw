#include "canvas_widget.hpp"
#include <iostream>
using namespace std;

CanvasWidget::CanvasWidget(QWidget * parent) : QWidget (parent) {

    cbox = new QGraphicsScene(this);
    QGraphicsView *main_box = new QGraphicsView(cbox, this);
    QBoxLayout *box_layout = new QVBoxLayout;
    box_layout->addWidget(main_box);
    this->setLayout(box_layout);
}


void CanvasWidget::addGraphic(QGraphicsItem * item) {
    cout << "ABOUT TO ADD THE GRAPHIC!" << endl;
    cbox->addItem(item);
}
