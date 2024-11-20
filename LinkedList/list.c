#include "list.h"
#include <stdlib.h>
#include <stdio.h>
//#define NDEBUG  //desactiva las aserciones
#include <assert.h>
struct node* BuildOneTwoThree(){
  struct node* head =malloc(sizeof(struct node));
  struct node* second =malloc(sizeof(struct node));
  struct node* third =malloc(sizeof(struct node));
  //struct node* head =(node*) malloc(sizeof(struct node*));
  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = 0;

  return head;
}
int size(struct node* head){
  int count = 0;
  while (head) {
    count++;
    head =  head ->next;
  }
  return count;
}
void pushInit(struct node** headRef, int newData){
  struct node* newNode = malloc(sizeof(struct node));
  newNode->data = newData;
  newNode->next = *headRef;
  *headRef = newNode;

  //(**headRef).before = newNode;
}
void print(struct node* head){
  if(!head){
    return ;
  }
  else{
    while (head) {
      printf("%d\n",head->data);
      head = head->next;
    }}
}
int getNth(struct node* head, int val){
  assert(head != NULL);
  assert(val >=0);
  assert(val < size(head)); 
  while(head && val){
    head = head->next;
    val--;
  }
  return head->data;
}
void deleteList(struct node** headRef){
  struct node* temp ;
  struct node* current = *headRef;
  while (current) {
    temp = current;
    current = current->next;
    free(temp);
  }
  *headRef=NULL;
}
