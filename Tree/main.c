#include <stdio.h>
#include "tree.h"
int main(int argc, char *argv[]){
  struct node* root = build123();
  if(hasPathSum2(root,6)){
    printf("si hay un camino");
  }
  else{
    printf("no hay un camino");
  }


  return 0;
}
