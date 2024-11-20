#ifndef TREE_H 
#define TREE_H
struct node {
  int data;
  struct node* left;
  struct node* right;
};
struct node* newNode(int data);
struct node* build123();
int size(struct node* node);
struct node* insert(struct node* node,int data);
int size(struct node* node);
void printInOr(struct node* node);
void printPosOr(struct node* node);
int maxDepth(struct node* node);
int minValue(struct node* node);
int hasPathSum(struct node* node, int sum);
void printPaths(struct node* node);

#endif // !DEBUG
