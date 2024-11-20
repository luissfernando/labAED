#include <stdio.h>
#include "list.h"
int main(int argc, char *argv[])
{
  struct node* head = BuildOneTwoThree();

  //pushInit(&head,5);
  //pushInit(&(head->next),6);
  //int contador = size(head);
  print(head);
  //getNth(head,-1);
  deleteList(&head);
  print(head);
  deleteList(&head);




}
