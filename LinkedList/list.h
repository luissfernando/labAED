#ifndef LIST_H
#define LIST_H
struct node{
  int data;
  struct node* next;
};

void print(struct node* head);
struct node* BuildOneTwoThree();
int size(struct node* head) ;
void pushInit(struct node** headRef, int newData);
#endif // DEBUG
