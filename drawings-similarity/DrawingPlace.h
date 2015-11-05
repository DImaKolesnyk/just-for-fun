#ifndef DRAWINGPLACE_H
#define DRAWINGPLACE_H

#include "QFrame"
#include<QPaintEvent>
#include <QPainter>
#include <QMouseEvent>
#include <contour.h>
#include <map>

class DrawingPlace : public QWidget
{
    Q_OBJECT
public:
    explicit DrawingPlace(QWidget *);
    void addContour( const Contour *, QPen );
    void changePenToContour(const Contour *c, QPen p) {
        contours[c] = p;
    }

    void drawCoordinateGrid(QPaintEvent *paint_event);

private:
        QPoint oldPos;
    std::map < const Contour *, QPen> contours;
    void paintEvent(QPaintEvent *paint_event);
    void mousePressEvent (QMouseEvent* pe);
    void mouseMoveEvent(QMouseEvent * event);
    void drawContour(QPaintEvent *);

signals:
    void DotCreated(QPoint);
    void mouseMove(QPoint);
};

#endif // DRAWINGPLACE_H
