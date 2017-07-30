//
// Created by Tom O'Brien on 30/07/2017.
//

#ifndef AVL_TREE_AVLTREE_H
#define AVL_TREE_AVLTREE_H

#include <stdbool.h>
#include "node.h"


class AVLTree {
private:
    int height;
    Node *head;
public:
    int get_height();
    Node *get_root();
    bool find(const int &k);
    AVLTree *insert(const int &k);
    AVLTree();
};


#endif //AVL_TREE_AVLTREE_H
