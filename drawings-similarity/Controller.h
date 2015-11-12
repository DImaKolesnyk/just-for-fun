#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "DrawingPlace.h"
#include "tree.h"
//#include "../../tree-iso/Hausdorff-master/src/hausdorff.h"

class Controller : public QObject
{
    Q_OBJECT

private:
    double eps_;
    Tree leftTree;
    Tree rightTree;
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
   bool isomorphic(const Tree &a, const Tree &b , double eps);
   bool frechet_dist(const Contour &a, const Contour &b, double eps);
   bool kuhn (Node* v, std::map <Node*, bool> &used, std::map <Node*, Node*> &mt, std::map <Node*, std::vector< Node* > > &g);
   bool maxMatchingAnswer(std::map<Node*, Node*> &g);
   std::map<Node*, Node*> findMaximumMatching(  std::vector<Node*> &a,   std::vector<Node*> &b, const std::vector< std::vector<bool> > &constraint );
   double getDistBetweenPointAndStraight(const QPoint &firstLinePoint,const QPoint &SecondLinePoint,const QPoint &point);

    void generateConstraint(std::vector< std::vector<bool> > &constraint, double eps);

   //Iso algo function
   void interval(QPoint x, QPoint y1, QPoint y2, double* a, double* b, double eps);
   double point_distance(QPoint a, QPoint b);
   QPoint point_mul(double x, QPoint a);
   double point_abs(QPoint a);
   double point_scalar(QPoint a, QPoint b);
   inline static void push(double a1, double b1, double* a2, double* b2);

public:
    Controller(DrawingPlace *lp, DrawingPlace *rp);

public slots:
//    void controleLeftWidget(QPoint);
    void addDotToLeftWidget(QPoint);
    void addDotToRightWidget(QPoint);
    void buttonClicked();
    void clearDrawingPlace();
    void epsChanged(double);
    void lengthBetweenMouseAndContour(QPoint);
signals:
    void changeLabel(QString);
};

#endif // CONTROLLER_H
