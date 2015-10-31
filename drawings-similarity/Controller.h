#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "DrawingPlace.h"

class Controller : public QObject
{
    Q_OBJECT

private:
   DrawingPlace *leftPlace;
   DrawingPlace *rightPlace;
   std::vector< Contour* > allLeftContour;
   std::vector< Contour* > allRightContour;
   void _RepaintAll();

public:
    Controller(DrawingPlace *lp, DrawingPlace *rp);

public slots:
    void addDotToLeftWidget(QPoint);
    void addDotToRightWidget(QPoint);
};

#endif // CONTROLLER_H
