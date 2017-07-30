//
// Created by Tom O'Brien on 30/07/2017.
//

#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H


class Node {
private:
    int k;
    Node *left;
    Node *right;
    short balance_factor;
public:
    int get_k();
    void set_k(const int &k);
    short get_balance_factor();
    void set_balance_factor(short b);
    Node* get_left();
    void set_left(Node *n);
    Node* get_right();
    void set_right(Node *n);

    Node();
    Node(const int &k);
};


#endif //AVL_TREE_NODE_H
