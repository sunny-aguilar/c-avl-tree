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

// function prototypes
struct AVLTree *newTree();
void initAVLTree(struct AVLTree *tree);
struct Node *newNode(struct Node *cur, int newValue);


int main() {
    struct AVLTree *tree = newTree();


    return 0;
}


struct AVLTree *newTree() {
    struct AVLTree *newTree = malloc(sizeof(struct AVLTree));
    assert(newTree != NULL);

    initAVLTree(newTree);
    return newTree;
}

void initAVLTree(struct AVLTree *tree) {
    assert(tree != NULL);
    tree->size = 0;
    tree->root = NULL;
}

struct Node *newNode(struct Node *cur, int newValue);
