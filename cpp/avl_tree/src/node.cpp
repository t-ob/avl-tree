//
// Created by Tom O'Brien on 30/07/2017.
//

#include "node.h"

Node::Node() {
    this->k = 0;
    this->balance_factor = 0;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(const int &k) {
    this->k = k;
    this->balance_factor = 0;
    this->left = nullptr;
    this->right = nullptr;
}

Node* Node::get_left() {
    return this->left;
}

void Node::set_left(Node *n) {
    this->left = n;
}

Node* Node::get_right() {
    return this->right;
}

void Node::set_right(Node *n) {
    this->right = n;
}

int Node::get_k() {
    return this->k;
}

void Node::set_k(const int &k) {
    this->k = k;
}

short Node::get_balance_factor() {
    return this->balance_factor;
}

void Node::set_balance_factor(short b) {
    this->balance_factor = b;
}
