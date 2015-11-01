#include "Controller.h"
#include <iostream>

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


bool Controller::nesting(const QPoint &test, const Contour &polygon  ) {
    static const int q_patt[2][2] = { {0,1}, {3,2} };

    if ( polygon.size() < 3 ) return false;

    QPoint pred_pt = polygon[polygon.size()-1];
    pred_pt.setX( pred_pt.x() - test.x() );
    pred_pt.setY( pred_pt.y() - test.y() );

    int pred_q = q_patt[ pred_pt.y() < 0 ][ pred_pt.x() < 0 ];
    int w = 0;

    for(int i = 0; i < polygon.size(); ++i ) {

        QPoint cur_pt = polygon[i];
        cur_pt.setX( cur_pt.x() - test.x() );
        cur_pt.setY( cur_pt.y() - test.y() );
        int q = q_patt[ cur_pt.y() < 0 ][ cur_pt.x() < 0 ];
        switch (q-pred_q) {
            case -3 : ++w; break;
            case  3 : --w; break;
            case -2 : if (   pred_pt.x() * cur_pt.y() >= pred_pt.y() * cur_pt.x()  ) ++w; break;
            case  2 : if ( !(pred_pt.x() * cur_pt.y() >= pred_pt.y() * cur_pt.x() ) ) --w; break;
        }
        pred_pt = cur_pt;
        pred_q = q;
    }

    return w!=0;

}




void Controller::buttonClicked() {


}
