#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
struct node {
  int data;
  struct node* left;
  struct node* right;
};

// Función para crear un nuevo nodo
struct node* newNode(int data) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

// Función para verificar si existe un camino con la suma dada
int hasPathSum(struct node* node, int sum) {
  // Caso base: nodo nulo
  if (node == NULL) {
    return 0;
  }

  // Restar el valor del nodo actual de la suma
  sum -= node->data;

  // Verificar si el nodo actual es una hoja
  if (node->left == NULL && node->right == NULL) {
    return sum == 0; // Retorna verdadero si la suma es 0
  }

  // Llamadas recursivas para los subárboles izquierdo y derecho
  if (node->left != NULL && hasPathSum(node->left, sum)) {
    return 1;
  }
  if (node->right != NULL && hasPathSum(node->right, sum)) {
    return 1;
  }

  // Retorna falso si no se encontró ningún camino con la suma dada
  return 0;
}

// Función para construir un árbol binario de ejemplo
struct node* buildTree() {
  struct node* root = newNode(3);
  root->left = newNode(2);
  root->right = newNode(5);
  root->left->left = newNode(1);
  root->right->right = newNode(6);
  root->right->left = newNode(4);
  return root;
}
int max(int a, int b){
  return (a>b) ? a : b;
}
int MaxTree(struct node* node){
  if(node==NULL){
    return 0;
  }
  else{
    int lefT = MaxTree(node->left);
    int righT = MaxTree(node->right);
    return max(max(node->data,lefT),righT);
  }
}
// Función principal
int main() {
  // Construir el árbol de ejemplo
  struct node* root = buildTree();

  // Suma a buscar
  int sum = 5;

  // Verificar si existe un camino con la suma dada
  if (hasPathSum(root, sum)) {
    printf("Hay un camino con suma %d.\n", sum);
  } else {
    printf("No hay un camino con suma %d.\n", sum);
  }
  printf("max = %d\n",MaxTree(root));

  // Liberar memoria (opcional para este ejemplo pequeño)
  /*free(root->left->left->left);  // Nodo 7
  free(root->left->left->right); // Nodo 2
  free(root->left->left);        // Nodo 11
  free(root->left);              // Nodo 4
  free(root->right->left);       // Nodo 13
  free(root->right->right);      // Nodo 4
  free(root->right);             // Nodo 8
  free(root);                    // Nodo raíz (5)
*/
  return 0;
}

/*void printPathsRecur(struct node* node, int path[],int pathLen){
                                  if(node==NULL){
                                  return ;}
                                  path[pathLen] = printPathsRecur(node->left,)
                                                                  }

void printPaths(struct node* node){
  int sizeP = size(node);
  int *path = malloc(sizeof(int)*sizeP);
  printPathsRecur(node,path,0);
}
*/
