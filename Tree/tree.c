#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
int min(int a,int b){
  return (a<b) ? a:b;
}
int max(int a,int b){
  return (a>b) ? a:b;
}
struct node* newNode(int data){
  struct node* node = malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}
struct node* build123(){
  struct node* root = insert(NULL,3);
  insert(root,2);
  insert(root,1);
  insert(root,5);
  insert(root,4);
  insert(root,6);
  insert(root,7);
  //insert(root,8);

  return root;
}
struct node* insert(struct node* node,int data){
  if(node){
    if(data <= node->data)
      node->left = insert(node->left,data);
    else 
      node->right = insert(node->right,data);
  }
  else{
    node = newNode(data);
  }
  return node;
}
int size(struct node* node){
  if(node==NULL){
    return 0;
  }
  return 1 + size(node->left)+ size(node->right);
}
void printInOr(struct node* root){
  if(root==NULL){
    return ;
  } 
  // else if(root->right==NULL && root->left==NULL){
  //}

  else{
    printInOr(root->left);
    int data= root->data;
    printf("%d ",data);

    printInOr(root->right);
  }
}
void printPosOr(struct node* node){
  if(node==NULL){
    return ;
  }

  else{
    printPosOr(node->left);
    printPosOr(node->right);
    printf("%d ", node->data);
  }
}
/*int countNode = 1;
int maxDepth(struct node* node){

  if(node== NULL){
    return 0;
  }
  else if(node->right==NULL && node->left==NULL) {
    printf("%d=>%d\n\n",node->data,countNode);
    countNode=1;

  }
  else{
    countNode++;
    maxDepth(node->left);
    maxDepth(node->right);

  }
}
*/ 
int maxDepth(struct node* node){
  if(node==NULL)
    return 0;
  else {
    return 1 + max(maxDepth(node->left),maxDepth(node->right));
  }
}
int minValue(struct node* node){
  assert(node!=NULL);
  if(node->left==NULL)
    return node->data;
  else{
    return minValue(node->left);
  }
}
int hasPathSum(struct node* node, int sum){
  assert(node!=NULL);
  if(node->left==NULL && node->right==NULL)
    return sum == 0; // expresion booleana FALSE
  else{
    return hasPathSum((node->left!=NULL) ? node->left : node ,sum - node->data)
    || hasPathSum((node->right!=NULL) ? node->right : node,sum - node->data);
  }
}
int hasPathSum2(struct node* node, int sum) {
    // Verificar si el nodo es NULL (caso base)
    if (node == NULL) {
        return 0; // No hay camino en un árbol vacío
    }

    // Restar el valor del nodo actual de la suma
    sum -= node->data;

    // Verificar si el nodo es una hoja
    if (node->left == NULL && node->right == NULL) {
        return sum == 0; // Si la suma restante es 0, se encontró el camino
    }

    // Llamadas recursivas a los subárboles izquierdo y derecho (solo si no son NULL)
    if (node->left != NULL && hasPathSum(node->left, sum)) {
        return 1;
    }
    if (node->right != NULL && hasPathSum(node->right, sum)) {
        return 1;
    }

    // Si no se encontró el camino, retornar 0
    return 0;
}

void printArray(int path[],int pathLen){
  for(int i=0;i<pathLen;i++)
    printf("%d ", path[i]);
  printf("\n");
}

