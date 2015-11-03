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
        tree.addNode(Node(-1, i));
        } else if ( buff[i].size() == 1 ) {
            tree.addNode(Node( buff[i][0], i ) );
        } else {
            tree.addNode( Node( internalContour(allContour, buff[i]), i ));
        }
    }
    return tree;
}

bool Controller::frechet_dist(const Contour &a, const Contour &b, double eps){
    return true;
}

bool Controller::try_kuhn (int v, std::vector<bool> &used, const std::vector <std::vector<int> > &g) {
    if (used[v])  return false;
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (mt[to] == -1 || try_kuhn (mt[to])) {
            mt[to] = v;
            return true;
        }
    }
    return false;
}

bool Controller::isomorphic(const Tree &a, const Tree &b) {

    bool iso = false;
    int aSize = a.getSortedTree().size();
    int bSize = b.getSortedTree().size();
    if( (allLeftContour.size() != allRightContour.size()) || (aSize != bSize) ) { return iso; }

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

    int n, k;
    std::vector<int> mt;
    std::vector<bool> used;
    std::vector < std::vector<int> > g;

    for(int i = 0; i < aSize; ++i ){


        mt.assign (k, -1);
        for (int v=0; v<n; ++v) {
            used.assign (n, false);
            try_kuhn (v, used, g);
        }
    }



}

void Controller::buttonClicked() {

    Tree leftTree;
    Tree rightTree;
    leftTree = createTree(allLeftContour);
    rightTree = createTree(allRightContour);
    leftTree.levelSort();
    rightTree.levelSort();

    leftTree.viewSorted();


}
