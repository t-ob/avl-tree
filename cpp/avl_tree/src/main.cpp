#include <iostream>
#include "AVLTree.h"

void show(AVLTree* tree) {
    Node *root = tree->get_root();
    Node *p;
    for (int depth = 0; depth <= tree->get_height(); ++depth) {
        int nodes = 1 << depth;
        for (int j = 0; j < nodes; ++j) {
            p = root;
            for (int k = 0; k < depth; ++k) {
                if (p == nullptr)
                    continue;

                int a = (j >> (depth - 1 - k)) & 1;
                if (a == 0) {
                    p = p->get_left();
                } else {
                    p = p->get_right();
                }
            }
            if (p != nullptr)
                std::cout << p->get_k() << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    AVLTree *tree = new AVLTree();

    static const int numbers[] = {13, 14, 5, 7, 8, 1, 15, 3, 11, 12, 2, 10, 9, 4, 6};
    for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); ++i) {
        tree->insert(numbers[i]);
    }

    show(tree);

    free(tree);

    tree = new AVLTree();
    for (int j = 1; j < 0x100; ++j) {
        tree->insert(j);
    }

    show(tree);

    free(tree);

    return 0;
}