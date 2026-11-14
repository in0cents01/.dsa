#include <stdio.h>
#include <stdlib.h>

// core concept idea
// temp   -> next newP
// temp   -> prev  = newP ;
// newP -> prev  = temp
// newP -> next = temp 2 ;
struct node {
  struct node  *prev ;
  int data ;
  struct node *next ;
} ;


struct node* addempty(struct node *head , int data) {
  struct node *temp  = (struct node* )malloc(sizeof(struct node)) ;
  temp  -> prev  = NULL;
  temp -> data  = data ;
  temp  -> next  = NULL;
  return temp ;
}
struct node* add_at_begin(struct node* head, int data) {

  struct node *temp  = (struct node*)malloc(sizeof(struct node)) ;
  temp -> prev  = NULL ;
  temp  -> data  = data ;
  temp -> next  = head ;
  if (head != NULL ) {
    head  -> prev  = temp ;
  }
  head  = temp ;
  return head ;
}
struct node* add_at_end(struct node* head , int data ) {
  struct node *temp  = (struct node*)malloc(sizeof(struct node)) ;
  temp  -> prev  = NULL ;
  temp  -> data  = data ;
  temp  -> next = NULL ;
  struct node *curr = head  ;
  while (curr -> next != NULL ) {
    curr  = curr -> next ;
  }
  curr  -> next  = temp ;
  temp -> prev  = curr ;
  return head ;

}
struct node* addAfterPos(struct node *head  , int data  , int pos) {
  struct node *newP  = NULL ;
  struct node *temp  = head ;
  struct node *temp2  = NULL ;
  newP  = addempty(newP  , data ) ;
  while (pos != 1) {
    temp  = temp  -> next;
    pos-- ;
  }
  temp2 = temp  -> next ;
  temp  -> next  = newP ;
  temp2 -> prev  = newP ;
  newP -> next = temp2 ;
  newP  -> prev  = temp ;
  return head ;
}

int main() {
  struct node* head  = (struct node* )malloc(sizeof(struct node)) ;
  int pos = 1 ;
  head = addempty(head  , 10) ;
  head = add_at_begin(head  , 20 )  ;
  head = add_at_end (head  , 9) ;
  head  = addAfterPos(head  , 45  , pos) ;

  struct node *ptr = NULL;
  ptr  = head ;
  while (ptr != NULL ) {
    printf(" %d " , ptr -> data) ;
    ptr  = ptr -> next ;
  }
  printf("\n") ;

  return  0;
}
