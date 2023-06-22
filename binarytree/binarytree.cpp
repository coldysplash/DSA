#include <iostream>

using namespace std;

struct bstree{
    int key; /* Ключ */
    char *value; /* Значение */
    struct bstree *left;
    struct bstree *right;
};

struct bstree *bstree_create(int key, char *value)
{
    struct bstree *node;
    node = new struct bstree;

    if (node != NULL) {
        node->key = key;
        node->value = value;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

void bstree_add(struct bstree *tree, int key, char *value){
    if (tree == NULL)
        return;
    struct bstree *parent, *node;
    while (tree != NULL) {
        parent = tree;
        if (key < tree->key)
            tree = tree->left;
        else if (key > tree->key)
            tree = tree->right;
        else
            return;
    }
    node = bstree_create(key, value);
    if (key < parent->key)
        parent->left = node;
    else
        parent->right = node;
}

struct bstree *bstree_lookup(struct bstree *tree, int key){
    while (tree != NULL) {
        if (key == tree->key)
            return tree;
        else if (key < tree->key)
            tree = tree->left;
        else
            tree = tree->right;
    }
    return tree;
}


int main()
{
    struct bstree *tree;
    struct bstree *node;
    tree = bstree_create(12, "Koala");
    bstree_add(tree, 4, "Flamingo");
    bstree_add(tree, 14, "Fox");
    node = bstree_lookup(tree, 4);
    printf("Found value for key %d: %s\n", node->key, node->value);
    return 0;
}