#include "qgraphics_arc_item.hpp"

#include <QGraphicsEllipseItem>
#include <QStyleOptionGraphicsItem>
#include <QPainter>


QGraphicsArcItem::QGraphicsArcItem(qreal x, qreal y, qreal width, qreal height, QGraphicsEllipseItem *parent) : QGraphicsEllipseItem(x, y, width, height, parent) {
//    painter = new QPainter;
}

void QGraphicsArcItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    //set default pen
    painter->setPen(pen());

    //set the default brush
    painter->setBrush(brush());

    //draw the arc
    painter->drawArc(rect(), startAngle(), spanAngle());
}
