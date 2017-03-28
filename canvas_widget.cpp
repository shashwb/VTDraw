#include "canvas_widget.hpp"

// Default construct a CanvasWidget
CanvasWidget::CanvasWidget(QWidget * parent) {

    canvasBox = new QGraphicsView;

}

// A public slot that accepts a signal in the form of a QGraphicsItem pointer containing an
// object derived from QGraphicsItem to draw
void addGraphic(QGraphicsItem * item) {

}
