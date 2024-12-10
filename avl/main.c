#include<stdio.h>
#include "avl.h"
int main(int argc, char* argv[]){
  struct AVL* root = NULL;
  /*printf("%d\n", balanceFactor(root));

  root = insertBST(root, 4);
  printf("%d\n", balanceFactor(root));

  root = insertBST(root, 2);
  printf("%d\n", balanceFactor(root));

  root = insertBST(root, 1);
  printf("%d\n", balanceFactor(root));

  root = insertBST(root, 3);
  printf("%d\n", balanceFactor(root));

  root = insertBST(root, 5);
  printf("%d\n", balanceFactor(root));
  */
  root = insertBST(root, 1);
  printf("%d\n", balanceFactor(root));
  root = insertBST(root, 2);
  printf("%d\n", balanceFactor(root));
  root = insertBST(root, 3);
  printf("%d\n", balanceFactor(root));

  root = leftRotation(root);
  root->parent = NULL;
  printf("%d\n", balanceFactor(root));

}
