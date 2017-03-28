#ifndef CANVAS_WIDGET_H
#define CANVAS_WIDGET_H

#include <QWidget>
#include <QString>
#include <QGraphicsWidget>
#include <QGraphicsView>


class CanvasWidget
{

//    Q_OBJECT

public:
    // Default construct a CanvasWidget
    CanvasWidget(QWidget * parent = nullptr);

    QGraphicsView *canvasBox;


public slots:
    // A public slot that accepts a signal in the form of a QGraphicsItem pointer containing an
    // object derived from QGraphicsItem to draw
    void addGraphic(QGraphicsItem * item);



};
#endif // CANVAS_WIDGET_H
