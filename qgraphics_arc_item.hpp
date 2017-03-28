#ifndef QGRAPHICS_ARC_ITEM_H
#define QGRAPHICS_ARC_ITEM_H

#include <QGraphicsEllipseItem>
#include <QWidget>

class QPainter;
class QStyleOptionGraphicsItem;
class QPointF;

class QGraphicsArcItem : public QGraphicsEllipseItem
{

//Q_OBJECT

public:
    QGraphicsArcItem(qreal x, qreal y, qreal width, qreal height, QGraphicsEllipseItem *parent = nullptr);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem * option, QWidget *widget = 0);

private:
//    QPainter * painter;

};


#endif // QGRAPHICS_ARC_ITEM_H
