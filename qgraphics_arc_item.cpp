#include "qgraphics_arc_item.hpp"

#include <QGraphicsEllipseItem>
#include <QStyleOptionGraphicsItem>
#include <QPainter>
#include <math.h>


QGraphicsArcItem::QGraphicsArcItem(qreal x, qreal y, qreal width, qreal height, qreal angle, QGraphicsEllipseItem *parent) : QGraphicsEllipseItem(x, y, width, height, parent) {
//    qreal radius = sqrt(pow((x - width), 2) + pow((y - height), 2));
//    qreal boundingBoxX = x - radius;
//    qreal boundingBoxY = y - radius;
//    qreal box_size = radius * 2;
//    double pi = atan2(0, -1);
//    double startAngle = (16 * (atan2(y - height, width - x) * (180 / pi)));
//    double spanAngle = (16 * (angle * (180 / pi)));
//    setRect(boundingBoxX, boundingBoxY, box_size, box_size);
//    setStartAngle((int)startAngle);
//    setSpanAngle((int)spanAngle);

}

void QGraphicsArcItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
//    painter->setPen(pen());
//    painter->setBrush(brush());
//    painter->drawArc(rect(), startAngle(), spanAngle());
}
