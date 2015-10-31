#ifndef DRAWINGPLACE_H
#define DRAWINGPLACE_H

#include "QFrame"
#include<QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <contour.h>
#include <map>

class DrawingPlace : public QFrame
{
    Q_OBJECT
public:
    explicit DrawingPlace(QWidget *);
    void addContour( const Contour *, QPen );
    void drawCoordinateGrid(QPaintEvent *paint_event);

private:
    std::map < const Contour *, QPen> contours;
    void paintEvent(QPaintEvent *paint_event);
    void mousePressEvent (QMouseEvent* pe);
    void drawContour(QPaintEvent *);

signals:
    void DotCreated(QPoint);
};

#endif // DRAWINGPLACE_H
