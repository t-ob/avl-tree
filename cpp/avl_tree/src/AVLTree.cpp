//
// Created by Tom O'Brien on 30/07/2017.
//

#include "AVLTree.h"

AVLTree::AVLTree() {
    Node* head = new Node();
    Node* height = new Node(0);
    head->set_left(height);
    this->head = head;
}

int AVLTree::get_height() {
    return head->get_left()->get_k();
}

Node* AVLTree::get_root() {
    return head->get_right();
}

bool AVLTree::find(const int &k) {
    Node *p = head->get_right();
    while (p != nullptr) {
        if (p->get_k() == k) {
            return true;
        }

        if (k < p->get_k()) {
            p = p->get_left();
        } else {
            p = p->get_right();
        }
    }

    return false;
}

AVLTree* AVLTree::insert(const int &k) {
    short a;
    Node *p, *q, *r, *s, *t;
    // Empty tree.
    if (head->get_right() == nullptr) {
        r = new Node(k);
        head->set_right(r);
        return this;
    }

    // Non-empty tree.

    // Initialise.
    // p moves down the tree, s points to where rebalancing may occur, and t points to the parent of s.
    t = head;
    s = p = head->get_right();

    // Compare and insert.
    while (p->get_k() != k) {
        if (k < p->get_k()) {
            q = p->get_left();
            if (q == nullptr) {
                q = new Node(k);
                p->set_left(q);
            } else if (q->get_balance_factor() != 0) {
                t = p;
                s = q;
            }

            p = q;
        } else if (k > p->get_k()) {
            q = p->get_right();
            if (q == nullptr) {
                q = new Node(k);
                p->set_right(q);
            } else if (q->get_balance_factor() != 0) {
                t = p;
                s = q;
            }

            p = q;
        } else {
            return this;
        }
    }

    // Adjust balance factors.
    a = (k < s->get_k() ? -1 : 1);
    r = p = (a == -1 ? s->get_left() : s->get_right());
    while (p != q) {
        if (k < p->get_k()) {
            p->set_balance_factor(-1);
            p = p->get_left();
        } else if (k > p->get_k()) {
            p->set_balance_factor(1);
            p = p->get_right();
        }
    }

    // Balancing act.
    if (s->get_balance_factor() == 0) {  // The tree has increased its height.
        s->set_balance_factor(a);
        head->get_left()->set_k(head->get_left()->get_k() + 1);
        return this;
    }

    if (s->get_balance_factor() == -a) {  // The tree has become more balanced.
        s->set_balance_factor(0);
        return this;
    }

    // Rebalancing is required.
    if  (r->get_balance_factor() == a) {  // Do a single rotation.
        p = r;
        if (a == -1) {
            s->set_left(r->get_right());
            r->set_right(s);
        } else {
            s->set_right(r->get_left());
            r->set_left(s);
        }
        s->set_balance_factor(0);
        r->set_balance_factor(0);
    } else {  // Do a double rotation.
        if (a == -1) {
            p = r->get_right();
            r->set_right(p->get_left());
            p->set_left(r);
            s->set_left(p->get_right());
            p->set_right(s);
        } else {
            p = r->get_left();
            r->set_left(p->get_right());
            p->set_right(r);
            s->set_right(p->get_left());
            p->set_left(s);
        }

        if (p->get_balance_factor() == a) {
            s->set_balance_factor(-a);
            r->set_balance_factor(0);
        } else if (p->get_balance_factor() == -a) {
            s->set_balance_factor(0);
            r->set_balance_factor(a);
        } else {
            s->set_balance_factor(0);
            r->set_balance_factor(0);
        }

        p->set_balance_factor(0);
    }

    // Finishing up.  Node p now points to new subtree root and requires reparenting.
    if (s == t->get_right()) {
        t->set_right(p);
    } else {
        t->set_left(p);
    }

    return this;
}
