#ifndef QGRAPHICS_ARC_ITEM_HPP
#define QGRAPHICS_ARC_ITEM_HPP

#include <QGraphicsEllipseItem>
#include <QWidget>

class QPainter;
class QStyleOptionGraphicsItem;
class QPointF;

class QGraphicsArcItem : public QGraphicsEllipseItem
{

//Q_OBJECT
public:
    QGraphicsArcItem(qreal x, qreal y, qreal width, qreal height, qreal angle, QGraphicsEllipseItem *parent = nullptr);
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget *widget = 0);
};


#endif // QGRAPHICS_ARC_ITEM_H
