#include "Controller.h"
#include <iostream>

Controller::Controller(DrawingPlace *lp, DrawingPlace *rp)  : leftPlace(lp), rightPlace(rp), windowActive(true)
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

bool Controller::frechet_dist(const Contour &a, const Contour &b, double eps){
    return true;
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

bool Controller::isomorphic(const Tree &a, const Tree &b) {

    int aSize = a.getSortedTree().size();
    int bSize = b.getSortedTree().size();
    if( (allLeftContour.size() != allRightContour.size()) || (aSize != bSize) ) { return false; }

   //Use Evgeniy Vodolazskiy algorithm to assign  array of constraint
    std::vector< std::vector<bool> > constraint;
    for(size_t i = 0; i < allLeftContour.size(); ++i){
        constraint.push_back(std::vector<bool>());
        for(size_t j = 0; j < allRightContour.size(); ++j) {
            constraint[i].push_back(frechet_dist(
                        (*(allLeftContour[i])),
                        (*(allRightContour[j])),
                        2
                        ));
        }
    }
    //----------------------------------------------------------------------------------


    std::vector< std::vector<Node*> >  a_sortedTree = a.getSortedTree();
    std::vector< std::vector<Node*> >  b_sortedTree = b.getSortedTree();

    std::map<Node*, Node*> currentMaxMatching;
    for ( int i = aSize-1; i >= 0; --i){
        currentMaxMatching = findMaximumMatching(a_sortedTree[i], b_sortedTree[i], constraint);
        if ( maxMatchingAnswer(currentMaxMatching)) {

            for ( auto  matchingNode : currentMaxMatching) {
                if ( !( constraint[matchingNode.first->getId()][matchingNode.second->getId()] ) ) {
                    return false;
                } else {
                    allMaximumMatchings.push_back( currentMaxMatching );
                }
            }

        } else {
            return false;
        }
    }


    return true;
}

void Controller::buttonClicked() {

    windowActive = false;

    Tree leftTree;
    Tree rightTree;
    leftTree = createTree(allLeftContour);
    rightTree = createTree(allRightContour);
    leftTree.levelSort();
    rightTree.levelSort();


    bool isoOtNot = isomorphic(leftTree, rightTree);
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
//            std::cout << di << std::endl;
            if( di < 5) {
                leftPlace->changePenToContour(allLeftContour[i], QPen(Qt::red, 4));

                //colored right matching colour
                for(int m = 0; m < allMaximumMatchings.size(); ++m) {
                    for(auto matchingPair : allMaximumMatchings[m]) {
                        if( matchingPair.first->getId() ==  i){
                            rightPlace->changePenToContour(allRightContour[matchingPair.second->getId()], QPen(Qt::red, 4));
                            if(coloredRightContourPosition[allRightContour[matchingPair.second->getId()]] == false) {
                                coloredRightContourPosition[allRightContour[matchingPair.second->getId()]] = true;
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
