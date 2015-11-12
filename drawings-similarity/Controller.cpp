#include "Controller.h"
#include <iostream>

Controller::Controller(DrawingPlace *lp, DrawingPlace *rp)  : leftPlace(lp), rightPlace(rp), windowActive(true), eps_(20)
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

    for(size_t i = 0; i < polygon.size(); ++i ) {

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
unsigned int Controller::internalContour(const  std::vector< Contour* > &allContour, const std::vector<int> &buff) {

            int nu;
            for (size_t i = 0; i < buff.size(); ++i) {
                nu = 0;
                for( size_t j = 0; j < buff.size(); ++j) {
                    if( nesting( (*(allContour[ buff[i] ]))[0],  (*(allContour[ buff[j] ])) )) {
                        nu +=1;
                    }
                }
                if(nu == buff.size() - 1) {return buff[i]; }
            }
}


Tree Controller::createTree(const  std::vector< Contour* > &allContour){

    Tree tree;
    std::vector <std::vector <int> > buff;
    for(size_t i = 0; i < allContour.size()-1 ; ++i ) {
        buff.push_back(std::vector<int>());
        for(size_t j = 0; j < allContour.size()-1; ++j ) {
            if (nesting( (*(allContour[i]))[0], (*(allContour[j])))) {
                buff[i].push_back(j);
            }
        }
    }
    for(size_t i = 0; i < buff.size(); ++i) {
        if (buff[i].size() == 0) {
        tree.addNode(new Node(-1, i));
        } else if ( buff[i].size() == 1 ) {
            tree.addNode(new Node( buff[i][0], i ) );
        } else {
            tree.addNode( new Node( internalContour(allContour, buff[i]), i ));
        }
    }
    return tree;
}

double Controller::point_scalar(QPoint a, QPoint b){
    return a.x()*b.x() + a.y()*b.y();
}

double Controller::point_abs(QPoint a){
    return sqrt(point_scalar(a, a));
}

QPoint Controller::point_mul(double x, QPoint a){
    return QPoint(x*a.x(),  x*a.y() );
}

double Controller::point_distance(QPoint a, QPoint b){
    return point_abs( QPoint(
                b.x() - a.x(),
                b.y()  - a.y()
                ));
}

inline void Controller::push(double a1, double b1, double* a2, double* b2){
    if (a1>*a2) *a2 = a1;
    if (a1>b1){
        *a2 = 1;
        *b2 = -1;
    }
}

void Controller::interval(QPoint x, QPoint y1, QPoint y2, double*  a, double* b, double eps){
    QPoint dy;
    dy = QPoint(y2.x() - y1.x(), y2.y() - y1.y());
    double alpha = point_scalar(dy, QPoint(x.x() - y1.x(), x.y() - y1.y()) )
                      /
                   ( pow( (point_abs(dy)), 2));
    QPoint theta = QPoint(
                point_mul(alpha, dy).x() + y1.x(),
                point_mul(alpha, dy).y() + y1.y()
                );
    double sqr_delta = eps*eps - pow( (point_distance(theta, x)), 2);
    if(sqr_delta<0){
        *a = 1;
        *b = -1;
        return;
    }
    double delta = sqrt(sqr_delta);
    *a = alpha*point_abs(dy)-delta;
    *b = alpha*point_abs(dy)+delta;
}

bool Controller::frechet_dist(const Contour &a, const Contour &b, double eps){
    int n = a.size() + 1;
    int m = 2*b.size() + 1;

    std::vector<std::vector< double > > ha(n, std::vector<double>(m));
    std::vector<std::vector< double > > hb(n, std::vector<double>(m));
    std::vector<std::vector< double > > va(n, std::vector<double>(m));
    std::vector<std::vector< double > > vb(n, std::vector<double>(m));


    int i, j;
    for(i=0; i<n; i++)
    for(j=0; j<m; j++){
        interval(
                    a[i%a.size()],
                    b[j%b.size()],
                    b[(j+1)%b.size()],
                    &va[i][j],
                    &vb[i][j],
                    eps);
        interval(
                    b[j%b.size()],
                    a[i%a.size()],
                    a[(i+1)%a.size()],
                    &ha[i][j],
                    &hb[i][j],
                    eps);
    }

    for(i=0; i<n; i++){
        ha[i][0] = 1;
        hb[i][0] = -1;
        ha[i][m-1] = 1;
        hb[i][m-1] = -1;
    }

    for(j=0; j<m; j++){
        if(j<b.size()){
            va[n-1][j] = 1;
            vb[n-1][j] = -1;
        }else{
            va[0][j] = 1;
            vb[0][j] = -1;
        }

    }

    int change = 1;
    while(change){
        change = 0;
        for(i=0; i<n-1; i++)
        for(j=0; j<m-1; j++){
            if(va[i][j] > vb[i][j]) push(ha[i][j], hb[i][j], &ha[i][j+1], &hb[i][j+1]);
            if(ha[i][j] > hb[i][j]) push(va[i][j], vb[i][j], &va[i+1][j], &vb[i+1][j]);
        }
        for(j=0; j<b.size();j++){
            if(va[0][j] < va[n-1][j+b.size()]){
                va[0][j] = va[n-1][j+b.size()];
                change = 1;
            }
        }

    }

    for(j=b.size(); j<2*b.size(); j++){
        if(va[a.size()][j]<vb[a.size()][j]) return true;
    }

    return false;
}

bool Controller::kuhn (Node*  v,
                                        std::map <Node*, bool> &used,
                                        std::map <Node*, Node*> &mt,
                                        std::map <Node*, std::vector< Node* > > &g) {
    if (used[v])  return false;
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        Node* to = g[v][i];
        if (mt[to] == nullptr || kuhn (mt[to], used, mt, g)) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

std::map<Node*, Node*> Controller::findMaximumMatching( std::vector<Node*> &a,   std::vector<Node*> &b, const std::vector< std::vector<bool> > &constraint ){

    int n = a.size();
    int k = b.size();
    if (n != k) return std::map<Node*, Node*>();

    //-------------------------------------------------------------- insert
    std::map <Node*, std::vector< Node* > > g;
    for(int i = 0; i < n; ++i ){
    g[a[i]] = std::vector<Node*>() ;
        for (int j = 0; j < k; ++j) {
            if( constraint[a[i]->getId()][ b[j]->getId()] ) {
                g[a[i]].push_back( b[j] );
            }
        }
    }
    //--------------------------------------------------------------
    std::map <Node*, Node*> mt;
    std::map <Node*, bool> used;

    for( int i = 0; i < k; ++i ) {
        mt[ b[i] ] = nullptr;
     }
     /*for ( int v = 0;  v < n; ++v )*/
    for (auto Node: a){
         for (int i = 0; i < n; ++i ){
             used[ a[i] ] = false;
         }
        kuhn( Node, used, mt, g);
     }

    return mt;
}

bool Controller::maxMatchingAnswer(std::map<Node*, Node*> &mt) {

    if( mt.size() == 0 ) {
        return false;
    }

    for (auto nodePair : mt) {
        if ( nodePair.second == nullptr ) {
                return false;
        }
    }

    return true;
}

void Controller::generateConstraint(std::vector< std::vector<bool> > &constraint, double eps) {

    //Use Evgeniy Vodolazskiy algorithm to assign  array of constraint
    for(size_t i = 0; i < allLeftContour.size()-1; ++i){
        constraint.push_back(std::vector<bool>());
        for(size_t j = 0; j < allRightContour.size()-1; ++j) {
            constraint[i].push_back(frechet_dist(
                        (*(allLeftContour[i])),
                        (*(allRightContour[j])),
                        eps
                        ));
        }
    }

}

bool Controller::isomorphic(const Tree &a, const Tree &b, double eps) {

    int aSize = a.getSortedTree().size();
    int bSize = b.getSortedTree().size();
    if( (allLeftContour.size() != allRightContour.size()) || (aSize != bSize) ) { return false; }
    std::vector< std::vector<bool> > constraint;
    generateConstraint(constraint, eps);
    std::vector< std::vector<Node*> >  a_sortedTree = a.getSortedTree();
    std::vector< std::vector<Node*> >  b_sortedTree = b.getSortedTree();
    std::map<Node*, Node*> currentMaxMatching;


    for ( int i = aSize-1; i >= 0; --i){
        currentMaxMatching = findMaximumMatching(a_sortedTree[i], b_sortedTree[i], constraint);
        if ( maxMatchingAnswer(currentMaxMatching)) {


            for ( auto  matchingNode : currentMaxMatching) {
                if( matchingNode.first->getFatherId() == -1) {
                   // allMaximumMatchings.push_back( currentMaxMatching );
                    break;
            }
                if ( !( constraint[matchingNode.second->getFatherId()][matchingNode.first->getFatherId()] ) ) {
                    return false;
                } /*else {
                    allMaximumMatchings.push_back( currentMaxMatching );
                }*/
            }
             allMaximumMatchings.push_back( currentMaxMatching );



        } else { return false; }
    }


    return true;
}

void Controller::buttonClicked() {

    windowActive = false;


    leftTree = createTree(allLeftContour);
    rightTree = createTree(allRightContour);
    leftTree.levelSort();
    rightTree.levelSort();


    bool isoOtNot = isomorphic(leftTree, rightTree, eps_);
    if (isoOtNot) {
        emit changeLabel("Similar images!");
    } else {
        emit changeLabel("Images not similar!");
    }

}

//void Controller::controleLeftWidget(QPoint p) {
//    if(windowActive) {
//        addDotToLeftWidget(p);
//    }
//}

double Controller::getDistBetweenPointAndStraight(const QPoint &p1, const QPoint &p2, const QPoint &point){

    int x = point.x();
    int y = point.y();
    int x1 = p1.x();
    int y1 = p1.y();
    int x2 = p2.x();
    int y2 = p2.y();

    double A = x - x1;
    double B = y - y1;
    double C = x2 - x1;
    double D = y2 - y1;

    double dot = A * C + B * D;
    double len_sq = C * C + D * D;
    double param = -1;
    if (len_sq != 0) //in case of 0 length line
        param = dot / len_sq;

    double xx, yy;

    if (param < 0) {
      xx = x1;
      yy = y1;
    }
    else if (param > 1) {
      xx = x2;
      yy = y2;
    } else {
      xx = x1 + param * C;
      yy = y1 + param * D;
    }

    double dx = x - xx;
    double dy = y - yy;
    return sqrt(dx * dx + dy * dy);
}


void Controller::lengthBetweenMouseAndContour(QPoint p) {
    leftPlace->setMouseTracking(true);
    if (!windowActive) {

      bool r = true;
    double di;
    for (int i = 0; i < allLeftContour.size(); ++i) {

        for (int j = 1; j < allLeftContour[i]->size(); ++j){
            di = getDistBetweenPointAndStraight( (*(allLeftContour[i]))[j-1], (*(allLeftContour[i]))[j], p);
            std::cout << di << std::endl;
            if( di < 5) {
                leftPlace->changePenToContour(allLeftContour[i], QPen(Qt::red, 4));

                //colored right matching colour
                for(int m = 0; m < allMaximumMatchings.size(); ++m) {
                    for(auto matchingPair : allMaximumMatchings[m]) {
                        if( matchingPair.second->getId() ==  i){
                            rightPlace->changePenToContour(allRightContour[matchingPair.first->getId()], QPen(Qt::red, 4));
                            if(coloredRightContourPosition[allRightContour[matchingPair.first->getId()]] == false) {
                                coloredRightContourPosition[allRightContour[matchingPair.first->getId()]] = true;
                            }
                        }
                    }
                }
                //-----------------------------------------

                if( coloredContourPosition [allLeftContour[i]] == false ) {
                    coloredContourPosition [allLeftContour[i]] = true;
                }
                r = false;
               _RepaintAll();
            }
        }

        if (r) {
            for(auto coloredBoolPair: coloredContourPosition) {
                leftPlace->changePenToContour(coloredBoolPair.first, QPen(Qt::blue, 2));
                leftPlace->repaint();
            }
            for(auto coloredRigtBoolPair : coloredRightContourPosition) {
                rightPlace->changePenToContour(coloredRigtBoolPair.first, QPen(Qt::blue, 2));
                rightPlace->repaint();
            }

        }
    }

    }
}

void Controller::clearDrawingPlace() {

    leftTree.clear();
    rightTree.clear();
    coloredContourPosition.clear();
    coloredRightContourPosition.clear();
    windowActive = true;
   leftPlace->clearContours();
   rightPlace->clearContours();
    allLeftContour.clear();
   allRightContour.clear();
   allMaximumMatchings.clear();
   _RepaintAll();

   Contour* newContour = new Contour;
   allLeftContour.push_back(newContour);
   leftPlace->addContour(newContour, QPen(Qt::blue, 2));
   rightPlace->addContour(newContour, QPen(Qt::gray, 1)) ;

   allRightContour.push_back(new Contour());
   rightPlace->addContour(*allRightContour.rbegin(), QPen(Qt::blue, 2));


}

void Controller::epsChanged(double e) {
    eps_ = e;
}
