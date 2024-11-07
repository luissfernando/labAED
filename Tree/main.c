#include <stdio.h>
#include "tree.h"
int main(int argc, char *argv[]){
  struct node* root = build123();
  printf("%d",hasPathSum(root,5));
  return 0;
}
