
//insert node add end in doubly linkedlist

#include <stdio.h>
#include <stdlib.h>

struct node  {

  struct node *prev  ;
  int data ;
  struct node *next ;
} ;

struct node* addEmpty(struct node *head, int data) {
  struct node *newNode = (struct node*)malloc(sizeof(struct node))  ;
  newNode -> prev  = NULL;
  newNode -> data  = data ;
  newNode -> next  = NULL ;

  head = newNode ;

  return head ;
}
struct node *add_at_begin(struct node *head  , int data) {

  struct node *temp  = (struct node*)malloc(sizeof(struct node)) ;
  temp  -> prev  = NULL ;
  temp  -> data  = data ;
  temp  -> next = NULL ;
  temp  -> next  = head ;
  head  -> prev  = temp ;
  head  = temp ;
  return head ;
}
struct node* add_at_end(struct node* head  ,int data ) {

  struct node *temp  = (struct node*)malloc(sizeof(struct node)) ;
  temp  -> prev  = NULL ;
  temp  -> data  = data ;
  temp -> next  = NULL ;
  struct node *tp  = NULL ;
  tp  = head ;
  while(tp -> next != NULL ) {
    tp  = tp  -> next ;
  }
  tp -> next  = temp ;
  temp -> prev  = tp ;
  return head ;

}

int main() {

  struct node *head  = (struct node*)malloc(sizeof(struct node)) ;
  head  = addEmpty(head , 10) ;
  head  = add_at_begin(head  , 20 ) ;
  head  = add_at_end(head  , 95) ;
  struct node *ptr  = NULL ;
  ptr  = head ;
  while (ptr != NULL )  {
    printf( " %d " , ptr  -> data ) ;
    ptr  =  ptr  -> next ;
  }
  printf("\n") ;

  return  0 ;
}
