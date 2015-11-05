#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "DrawingPlace.h"
#include "tree.h"
//#include "../../tree-iso/Hausdorff-master/src/hausdorff.h"

class Controller : public QObject
{
    Q_OBJECT

private:
    std::map<Contour*, bool> coloredContourPosition;
     std::map<Contour*, bool> coloredRightContourPosition;
    bool windowActive;
   DrawingPlace *leftPlace;
   DrawingPlace *rightPlace;
   std::vector< Contour* > allLeftContour;
   std::vector< Contour* > allRightContour;
   std::vector< std::map<Node*, Node*> > allMaximumMatchings;
   void _RepaintAll();
   bool nesting(const QPoint &test, const Contour &polygon  );
   unsigned int internalContour(const  std::vector< Contour* > &allContour, const std::vector<int> &buff);
   Tree createTree(const  std::vector< Contour* > &allContour);
   bool isomorphic(const Tree &a, const Tree &b );
   bool frechet_dist(const Contour &a, const Contour &b, double eps);
   bool kuhn (Node* v, std::map <Node*, bool> &used, std::map <Node*, Node*> &mt, std::map <Node*, std::vector< Node* > > &g);
   bool maxMatchingAnswer(std::map<Node*, Node*> &g);
   std::map<Node*, Node*> findMaximumMatching(  std::vector<Node*> &a,   std::vector<Node*> &b, const std::vector< std::vector<bool> > &constraint );
   double getDistBetweenPointAndStraight(const QPoint &firstLinePoint,const QPoint &SecondLinePoint,const QPoint &point);

public:
    Controller(DrawingPlace *lp, DrawingPlace *rp);

public slots:
//    void controleLeftWidget(QPoint);
    void addDotToLeftWidget(QPoint);
    void addDotToRightWidget(QPoint);
    void buttonClicked();
    void lengthBetweenMouseAndContour(QPoint);
signals:
    void changeLabel(QString);
};

#endif // CONTROLLER_H
