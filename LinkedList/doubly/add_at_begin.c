#include <stdio.h>
#include <stdlib.h>

struct node  {

  struct node *prev   ;
  int data ;
  struct node *next ;

} ;

struct node* add_empty(struct node* head  , int data ) {

  struct node *temp =  (struct node*)malloc(sizeof(struct node)) ;
  temp  -> prev  = NULL ;
  temp  -> data  = data ;
  temp  -> next  = NULL ;
  head  = temp ;
  return head ;
}

struct node* add_ad_begin(struct node *head  , int data ) {

  //core concept
  // temp  -> next  = head ;
  // head  -> prev  = temp
  // head  = temp

  struct node *temp  = (struct node*)malloc(sizeof(struct node));
  temp  -> prev  = NULL;
  temp -> data  = data ;
  temp -> next = NULL;
  temp -> next  = head ;
  head  -> prev  = temp ;
  head  = temp ;
  return head ;
}
int main(void) {
  struct node *head  = NULL ;
  head = add_empty(head  , 10) ; 
  head  = add_ad_begin(head , 20 ) ; 
  struct node *ptr  = head ; 
  while (ptr != NULL) {
    printf(" %d " , ptr  -> data ) ; 
    ptr  = ptr  -> next ; 
  } 
  printf("\n") ; 
  return  0 ;
}
