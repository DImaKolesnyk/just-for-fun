//
// Created by dima on 10.09.15.
//

#include <QFrame>
#include <iostream>
#include "Visualizer.h"



Visualizer::Visualizer(const std::vector<std::vector<double> > &data_, const std::vector<double> &line_): data(data_), line(line_) {

    this->setGeometry(0,0,500,500);
    this->setStyleSheet("background-color: white;");
}

Visualizer::~Visualizer() {

}

void Visualizer::drawCoordinate(QPaintEvent *paint_event) {


        QWidget::paintEvent(paint_event);
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

void Visualizer::drawDots(QPaintEvent *p) {

    QPainter painter(this);
    QPen bluePen( Qt::blue, 2 );
    QPen greenPen( Qt::darkGreen, 2);

    int windowHeight = this->size().height();
    int windowWidth =  this->size().width();


    for (int k = 0; k < data.size(); ++k) {

        if (data[k][2] == 0 ) {
            painter.setPen(bluePen);
        } else {
            painter.setPen(greenPen);
        }
        painter.drawEllipse(QPoint(windowWidth*data[k][0], windowHeight*data[k][1]), 2, 2);
    }



}

void Visualizer::drawLine(QPaintEvent *p) {

    int windowHeight = this->size().height();
    int windowWidth =  this->size().width();

    QPainter painter(this);
    QPen redPen(Qt::red, 2);
    painter.setPen(redPen);

    double line1X = line[2]/line[0];
    double line2X = (line[2] - line[1]) / line[0];
    painter.drawLine(QPoint(windowWidth*line1X, 0 ), QPoint(windowWidth *line2X, windowHeight) );

}


void Visualizer::paintEvent(QPaintEvent *paint_event) {

    drawCoordinate(paint_event);
    drawDots(paint_event);
    drawLine(paint_event);
}