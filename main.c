#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct AVLTree {
    int size;
    struct AVLNode *root;
};

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
    int height;
};

struct AVLTree *newTree();
void initAVLTree(struct AVLTree *tree);

int main() {
    struct AVLTree *tree = newTree();

    return 0;
}

struct AVLTree *newTree() {

    return null;
}

void initAVLTree(struct AVLTree *tree) {
    assert(tree != NULL);
}