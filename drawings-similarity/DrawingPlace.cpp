#include "DrawingPlace.h"
#include<QtMath>

DrawingPlace::DrawingPlace(QWidget *)
{
}

void DrawingPlace::drawCoordinateGrid(QPaintEvent *paint_event)
{
    QFrame::paintEvent(paint_event);
    int windowHeight = this->size().height();
    int windowWidth =  this->size().width();
    const int lineInterval = 20; // interval between two lines

    QPainter painter(this);
    QPen penGray(QColor(0, 0, 0, 25), 1);

    QPoint vertLineP1(0,0);
    QPoint vertLineP2(0, windowHeight);

    painter.setPen(penGray);
    //---------------------------------draw vertical lines
    for ( int i = 0; i < windowWidth/lineInterval; ++i ) {
        vertLineP1.setX( vertLineP1.x() + lineInterval);
        vertLineP2.setX( vertLineP2.x() + lineInterval);
        painter.drawLine(vertLineP1,vertLineP2);
    }

    QPoint horLineP1(0,0);
    QPoint horLineP2(windowWidth, 0);

    //---------------------------------draw horisontal lines

    for (int i = 0; i < windowHeight/lineInterval; ++i) {
        horLineP1.setY(horLineP1.y() + lineInterval);
        horLineP2.setY(horLineP2.y() + lineInterval);
        painter.drawLine(horLineP1, horLineP2);
    }
}

void DrawingPlace::drawContour(QPaintEvent *)
{
    QPainter painter(this);
    QPen penDarkGray(Qt::darkGray, 3);
    QPen bluePen( Qt::blue, 2 );


    for (auto contourPair : contours) {
        for ( size_t i = 1; i < contourPair.first->size(); ++i) {

            painter.setPen(contourPair.second);
            painter.drawLine( (*(contourPair.first))[i-1], (*(contourPair.first))[i] );
        }
    }


    painter.setPen(penDarkGray);
        for (auto contourPair : contours) {
            if (contourPair.second == QPen(Qt::blue, 2) ) {
            for (size_t j = 0; j < contourPair.first->size(); ++j) {
                painter.drawEllipse(
                            (*(contourPair.first))[j], 2,2
                            );
            }
            }
        }

}

void DrawingPlace::paintEvent(QPaintEvent *paint_event)
{
    drawContour(paint_event);
    drawCoordinateGrid(paint_event);
}


void DrawingPlace::mousePressEvent(QMouseEvent *pe)
{
    emit DotCreated(pe->pos());
}

void DrawingPlace::addContour( const  Contour * c, QPen qpen) {
    contours[c] = qpen;
}
