#include <stdio.h>
#include "list.h"
int main(int argc, char *argv[])
{
  struct node* head = BuildOneTwoThree();
  int contador = size(head);

  pushInit(&head,5);
  print(head);

}
