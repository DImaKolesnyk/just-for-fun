#ifndef TREE_H
#define TREE_H
#include <vector>
#include <node.h>
#include <iostream>

class Tree {

private:
    std::vector<Node> treeNode;

public:
    Tree() {}
    void view() {
        for(int i = 0; i < treeNode.size(); ++i){
            std::cout << "( " << treeNode[i].getFatherId() << ", " << treeNode[i].getId() << ") " << std::endl;
        }
    }

    void addNode(const Node &n  ) {treeNode.push_back(n); }


};

#endif // TREE_H

