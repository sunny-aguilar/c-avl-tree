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
struct Node *balance(struct Node *cur);
int bf(struct Node *cur);
struct Node *rotateLeft(struct Node *cur);
struct Node *rotateRight(struct Node *cur);
void setHeight();


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

struct Node *newNode(struct Node *cur, int newValue) {
    assert(cur != NULL && newValue != 0);
    if (cur == NULL) {
        struct Node *newNode = malloc(sizeof(struct Node));
        assert(newNode != NULL);
        newNode->value = newValue;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    else if (newValue < cur->value) {
        cur->left = newNode(cur->left, newValue);
    }
    else {
        cur->right = newNode(cur->right, newValue);
    }

    return cur;
}

struct Node *balance(struct Node *cur) {
    assert(cur != NULL);
    int cbf = bf(cur);

    if (cbf < -1) {
        if (bf (cur->left) > 0) {
            cur->left = rotateLeft(cur->left);
        }
        return rotateRight(cur);
    }
    else if (cbf > 1) {
        if (bf(cur->right) < 0) {
            cur->right = rotateRight(cur->right);
        }
        return rotateLeft(cur);
    }
    setHeight(cur);
    return cur;
}

struct Node *rotateLeft(struct Node *cur) {
    assert(cur != NULL);
    struct Node *newTop = cur->right;
    cur->right = newTop->left;
    newTop->left = cur;
    setHeight(cur);
    setHeight(newTop);
    return newTop;
}