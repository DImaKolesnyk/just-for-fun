#ifndef TREE_H
#define TREE_H
#include <vector>
#include <node.h>
#include <iostream>

class Tree {

private:
    std::vector<Node> treeNode;
    std::vector< std::vector<Node*> > sortedTree;

    void alloc(unsigned int size, std::vector< std::vector<Node*> > &st) {
        if (size+1 > st.size() ) {
            st.resize(size+1);
        }
    }

    Node find(int id) {
        int i = 0;
        while( treeNode[i].getId() != id ) {
            ++i;
        }
        return treeNode[i];
    }

public:
    Tree() {}
    void view() {
        for(size_t i = 0; i < treeNode.size(); ++i){
            std::cout << "( " << treeNode[i].getFatherId() << ", " << treeNode[i].getId() << ") " << std::endl;
        }
    }

    void viewSorted(){
        int k = 0;
        for ( auto levelVector : sortedTree ) {
            std::cout << k << ": ";
            for(int i = 0; i < levelVector.size(); ++i) {
                std::cout << levelVector[i]->getId() << ", ";
            }
            std::cout << std::endl;
            ++k;
        }
    }

     std::vector< std::vector<Node*> > getSortedTree() {
         return sortedTree;
     }

    void addNode(const Node &n  ) {treeNode.push_back(n); }
    void levelSort() {
        int nodeFather;
        unsigned int level = 0;
        for(size_t i = 0; i < treeNode.size(); ++i) {
            nodeFather = treeNode[i].getFatherId();
            while( nodeFather != -1 ) {
                   nodeFather =  find(nodeFather).getFatherId();
                   ++level;
            }

            alloc(level, sortedTree);
            sortedTree[level].push_back(&(treeNode[i]) );
             level = 0;
        }
    }


};

#endif // TREE_H

