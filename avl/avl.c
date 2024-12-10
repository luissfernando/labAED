#include<stdio.h>
#include<stdlib.h>
#include "avl.h"
#include <assert.h>

int max(int a, int b){
  return (a > b) ? a : b;
}

int abs(int a){
  return (a < 0) ? -a : a;
}

struct AVL* newNode(int data){
  struct AVL* node = malloc(sizeof(struct AVL));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
  return node;
}

  struct AVL* insertBST(struct AVL* node, int data){
    if(!node)
      return newNode(data);
    if(data < node->data){
      node->left = insertBST(node->left, data);
      node->left->parent = node;
    }else{
      node->right = insertBST(node->right, data);
      node->right->parent = node;
    }
    return node;
  }
  int height(struct AVL* node){
    if(!node) return -1;
    return 1 + max(height(node->left), height(node->right));
  }
  int balanceFactor(struct AVL* node){
    if(!node) return 0;
    return height(node->right) - height(node->left);
  }
  int isAVL(struct AVL* node){
    if(!node) return 1;
    return (abs(balanceFactor(node)) <= 1) &&
    isAVL(node->left) &&
    isAVL(node->right);
  }
  struct AVL* leftRotation(struct AVL* node){
    assert(node);
    struct AVL* x = node;
    struct AVL* y = node->right;
    assert(y);
    struct AVL* b = node->right->left;
    //assert(b);
    //struct AVL* xParent = x->parent;

    // padre he aqui a tu hijo ,hijo he aqui a tu padre
    x->right = b;
    if(b)
      b->parent = x;

    y->left = x;
    x->parent= y;

    //xParent = 
    /*if(xParent != NULL){
      if(xParent->left = x){
        xParent->left = y;
      }
      else{
        xParent->right= y;
      }
    }*/

    //y->parent = xParent;
    assert(y);
    return y;
  }
