#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LLRBtree {
  int key;
  int value;
  bool color; // true == RED; false == BLACK
  struct LLRBtree *right;
  struct LLRBtree *left;

} LLRBtree;

LLRBtree *root;

LLRBtree *createnode(LLRBtree *T, int key, int value) {

  LLRBtree *Node = (LLRBtree *)malloc(sizeof(LLRBtree));

  if (Node != NULL) {
    if (T == NULL) {
      Node->color = false;
    } else {
      Node->color = true; // При создании нового узла он всегда красный
    }
    Node->key = key;
    Node->value = value;
    Node->left = NULL;
    Node->right = NULL;
  }

  return Node;
}

LLRBtree *rotateLeft(LLRBtree *h) {
  LLRBtree *x;
  x = h->right;
  h->right = x->left;
  x->left = h;
  x->color = h->color;
  h->color = true; // Red

  return x;
}

LLRBtree *rotateRight(LLRBtree *h) {
  LLRBtree *x;
  x = h->left;
  h->left = x->right;
  x->right = h;
  x->color = h->color;
  h->color = true; // Red

  return x;
}

void flipColors(LLRBtree *h) {
  // родитель окрашивается в красный цвет
  h->color = !h->color;
  // левый и правый потомок окрашиваются в черный цвет
  h->left->color = !h->left->color;
  h->right->color = !h->right->color;
}

// служебная функция чтобы проверить окрашен ли узел в красный цвет или нет
bool isRed(LLRBtree *Node) {
  if (Node == NULL) {
    return 0;
  }
  if (Node->color == true) {
    return true;
  } else {
    return false;
  }
}

LLRBtree *insert(LLRBtree *h, int key, int value) {
  if (h == NULL) {
    return createnode(h, key, value);
  }
  if (value < h->value) {
    h->left = insert(h->left, key, value);
  } else if (value > h->value) {
    h->right = insert(h->right, key, value);
  } else {
    return h;
  }

  // case 1 когда левый и правый "ребёнок" красные вызываем функцию flipColors
  if (isRed(h->left) && isRed(h->right)) {
    flipColors(h);
  }

  // case 2 когда правый дочерний элемент красный, а левый дочерний элемент
  // черный или его не существует
  if (isRed(h->right) && !isRed(h->left)) {
    h = rotateLeft(h);
  }

  // case 3 когда левый "ребёнок" и "внук" красные
  if (isRed(h->left) && isRed(h->left->left)) {
    h = rotateRight(h);
  }

  return h;
}

LLRBtree *search(LLRBtree *T, int key) {
  while (T != NULL) {
    if (key == T->key)
      return T;
    else if (key < T->key)
      T = T->left;
    else
      T = T->right;
  }
  return T;
}

int my_compare(unsigned int key1, unsigned int key2) {
  return ((key1 == key2) ? (0) : ((key1 < key2) ? (-1) : (1)));
}

LLRBtree *fixUP(LLRBtree *node) {
  if (isRed(node->right))
    node = rotateLeft(node);
  if (isRed(node->left) && isRed(node->left->left))
    node = rotateRight(node);
  if (isRed(node->left) && isRed(node->right))
    flipColors(node);
  return node;
}

LLRBtree *move_red_to_left(LLRBtree *node) {
  flipColors(node);
  if (node && node->right && isRed(node->right->left)) {
    node->right = rotateRight(node->right);
    node = rotateLeft(node);
    flipColors(node);
  }
  return node;
}

LLRBtree *move_red_to_right(LLRBtree *node) {
  flipColors(node);
  if (node && node->left && isRed(node->left->left)) {
    node = rotateRight(node);
    flipColors(node);
  }
  return node;
}

LLRBtree *min(LLRBtree *node) {
  if (!node)
    return ((LLRBtree *)0);
  while (node->left)
    node = node->left;
  return node;
}

LLRBtree *delete_min(LLRBtree *node) {
  if (!node)
    return ((LLRBtree *)0);
  if (!node->left) {
    free(node);
    return ((LLRBtree *)0);
  }
  if (!isRed(node->left) && !isRed(node->left->left))
    node = move_red_to_left(node);
  node->left = delete_min(node->left);
  return fixUP(node);
}

LLRBtree *delete (LLRBtree *node, int key);

LLRBtree *deletekey(LLRBtree *node, int key) {
  node = delete (node, key);
  if (node) {
    node->color = false;
  }
  return node;
}

LLRBtree *delete (LLRBtree *node, int key) {
  LLRBtree *tmp;
  if (!node)
    return ((LLRBtree *)0);

  if (my_compare(key, node->key) == -1) {
    if (node->left) {
      if (!isRed(node->left) && !isRed(node->left->left))
        node = move_red_to_left(node);
      node->left = deletekey(node->left, key);
    }
  } else {
    if (isRed(node->left))
      node = rotateRight(node);
    if (!my_compare(key, node->key) && !node->right) {
      free(node);
      return ((LLRBtree *)0);
    }
    if (node->right) {
      if (!isRed(node->right) && !isRed(node->right->left))
        node = move_red_to_right(node);
      if (!my_compare(key, node->key)) {
        tmp = min(node->right);
        node->key = tmp->key;
        node->value = tmp->value;
        node->right = delete_min(node->right);
      } else {
        node->right = deletekey(node->right, key);
      }
    }
  }

  return fixUP(node);
}

void preorder(LLRBtree *node) {
  if (node) {
    preorder(node->left);
    printf("%d ", node->value);
    preorder(node->right);
  }
}

int main() {
  root = NULL;

  root = insert(root, 1, 10);
  root->color = false;

  root = insert(root, 2, 20);

  root = insert(root, 3, 30);

  root = insert(root, 4, 40);

  root = insert(root, 5, 50);

  root = insert(root, 6, 25);

  preorder(root);
  return 0;
}