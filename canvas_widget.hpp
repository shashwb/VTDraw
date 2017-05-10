#ifndef CANVAS_WIDGET_HPP
#define CANVAS_WIDGET_HPP
#include <QGraphicsItem>
#include <QBoxLayout>
#include <QString>
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>


class CanvasWidget: public QWidget {
    Q_OBJECT
public:
    QGraphicsScene *cbox;
    CanvasWidget(QWidget * parent = nullptr);

public slots:
    void addGraphic(QGraphicsItem * item);
private:

};

#endif
