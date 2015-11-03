#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "DrawingPlace.h"
#include "tree.h"
//#include "../../tree-iso/Hausdorff-master/src/hausdorff.h"

class Controller : public QObject
{
    Q_OBJECT

private:
   DrawingPlace *leftPlace;
   DrawingPlace *rightPlace;
   std::vector< Contour* > allLeftContour;
   std::vector< Contour* > allRightContour;
   void _RepaintAll();
   bool nesting(const QPoint &test, const Contour &polygon  );
   unsigned int internalContour(const  std::vector< Contour* > &allContour, const std::vector<int> &buff);
   Tree createTree(const  std::vector< Contour* > &allContour);
   bool isomorphic(const Tree &a, const Tree &b );
   bool frechet_dist(const Contour &a, const Contour &b, double eps);
   bool try_kuhn (int v, std::vector<bool> &used, const std::vector <std::vector<int> > &g);

public:
    Controller(DrawingPlace *lp, DrawingPlace *rp);

public slots:
    void addDotToLeftWidget(QPoint);
    void addDotToRightWidget(QPoint);
    void buttonClicked();
};

#endif // CONTROLLER_H
