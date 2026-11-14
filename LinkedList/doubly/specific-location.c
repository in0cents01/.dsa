#include <stdio.h>
#include <stdlib.h>


struct node {

  struct node *prev ;
  int data ;
  struct node *next ;
} ;

struct node* addempty(struct node *head  , int data ) {

  struct node *temp = (struct node*)malloc(sizeof(struct node)) ;
  temp  -> prev  = NULL  ;
  temp  -> data  = data ;
  temp  -> next = NULL ;
  return temp ;
}
struct node* add_at_begin(struct node *head , int data ) {

  struct node *temp  = (struct node*)malloc(sizeof(struct node)) ;
  temp  -> prev  = NULL  ;
  temp  -> data = data ;
  temp  -> next = NULL ;
  temp -> next  = head ;
  head  -> prev  = temp ;
  head  = temp ;
  return head ;
}
struct node* add_at_end(struct node *head , int data ) {

  struct node *temp  = (struct node*)malloc(sizeof(struct node)) ;
  temp  -> prev  = NULL ;
  temp -> data  = data ;
  temp  -> next = NULL ;
  struct node *curr = head ;
  while (curr -> next != NULL ) {
    curr  = curr -> next ;
  }
  curr -> next  = temp ;
  temp  -> prev  = curr ;
  return head ;
}
struct node* addbeforpos (struct node *head  , int data  , int pos) {

  struct node *newp = NULL;
  struct node *temp = head ;
  struct node *temp2 = NULL ;

  if (pos  == 1) {
    head  = add_at_begin(head , data ) ;
  }
  else {
    newp  = (struct node*)malloc(sizeof(struct node)) ;
    newp  -> prev  = NULL ;
    newp  -> data  = data ;
    newp  -> next  = NULL ;
    while (pos > 2) {
      temp  = temp  -> next ;
      pos-- ;
    }
    temp2 = temp -> next ;
    temp  -> next =  newp ;
    newp  -> prev  = temp ;
    newp  -> next  = temp2 ;
    temp2 -> prev  = newp ;
  }
  return head ;
}

int main() {

  struct node *head  = NULL ;

  const  int pos  = 3 ;
  head  = addempty(head , 10) ;
  head  = add_at_begin(head  , 5) ;
  head  =  add_at_end (head , 45) ;
  head  = addbeforpos(head , 90  , pos) ;
  struct node *ptr  = NULL ;
  ptr  = head ;
  while (ptr != NULL ) {
    printf(" %d "  , ptr  -> data) ;
    ptr  =  ptr  -> next ;
  }
  printf("\n") ;
  return  0 ;
}
