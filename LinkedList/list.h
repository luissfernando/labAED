#ifndef LIST_H
#define LIST_H
struct node{
  int data;
  struct node* next;
  struct node* before;
};

void print(struct node* head);
struct node* BuildOneTwoThree();
int size(struct node* head) ;
void pushInit(struct node** headRef, int newData);
void getNthTest();
int getNth(struct node* head,int val);
void deleteList(struct node** list);
#endif // DEBUG
