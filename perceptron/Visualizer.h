//
// Created by dima on 10.09.15.
//

#ifndef PERCEPTRON_VISUALIZER_H
#define PERCEPTRON_VISUALIZER_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

class Visualizer : public QWidget {
private:
    std::vector< std::vector< double> > data;
    std::vector <double> line;
public:
    Visualizer(const std::vector< std::vector< double> > &data, const std::vector <double> &line);
    void drawCoordinate( QPaintEvent *paint_event);
    void drawDots( QPaintEvent *p);
    void drawLine( QPaintEvent *p);
    ~Visualizer();

protected:
    void paintEvent(QPaintEvent *paint_event);
};


#endif //PERCEPTRON_VISUALIZER_H
