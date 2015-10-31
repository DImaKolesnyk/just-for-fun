#include "Controller.h"

Controller::Controller(DrawingPlace *lp, DrawingPlace *rp)  : leftPlace(lp), rightPlace(rp)
{
    Contour* newContour = new Contour;
    allLeftContour.push_back(newContour);
    leftPlace->addContour(newContour, QPen(Qt::blue, 2));
    rightPlace->addContour(newContour, QPen(Qt::gray, 1)) ;

    allRightContour.push_back(new Contour());
    rightPlace->addContour(*allRightContour.rbegin(), QPen(Qt::blue, 2));
}

void Controller::_RepaintAll()
{
leftPlace->repaint();
rightPlace->repaint();
}

void Controller::addDotToLeftWidget(QPoint p) {
    Contour* lastContour = *allLeftContour.rbegin();
    lastContour->addDot(p);
    if(lastContour->full())
    {
        Contour* newContour = new Contour();
        allLeftContour.push_back(newContour);
        leftPlace->addContour(newContour, QPen(Qt::blue, 2)); // , blue
        rightPlace->addContour(newContour, QPen(Qt::gray, 1)); // grey
    }
    _RepaintAll();
}

void Controller::addDotToRightWidget(QPoint p) {
    Contour* lastContour = *allRightContour.rbegin();
    lastContour->addDot(p);
    if(lastContour->full())
    {
        Contour* newContour = new Contour();
        allRightContour.push_back(newContour);
        rightPlace->addContour(newContour, QPen(Qt::blue, 2)); // blue
    }
    _RepaintAll();
}
