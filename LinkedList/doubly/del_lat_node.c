// concept idea
// head  , temp  => of node
// while (temp  -> next != NULL )  look like insert node at end
// temp  = temp -> next
//temp2  = temp  -> prev
// temp2  -> nxt  = NULL
// free(temp)
// temp = NULL  (it finally suceess )


#include <stdio.h>
#include <stdlib.h>


struct node {
  struct node *prev ;
  int data ;
  struct node *next ;
} ;

struct node *addempty(struct node *head  , int data) {

  struct node *temp  = (struct node*)malloc(sizeof(struct node)) ;
  temp  -> prev  = NULL ;
  temp  -> data  = data ;
  temp  -> next  = NULL ;
  return temp ;
}
struct node *add_at_end(struct node *head  , int data) {

  struct node *temp  = (struct node*) malloc(sizeof(struct node)) ;
  temp  -> prev  = NULL ;
  temp  -> data  = data ;
  temp  -> next  = NULL ;
  struct node *curr  = head ;
  while (curr  -> next != NULL ) {
    curr  = curr -> next ;
  }
  curr  -> next  = temp ;
  temp  -> prev  = curr ;
  return head ;
}
struct node *del_lastNode(struct node* head ) {

  struct node *temp  = head ;
  struct node *temp2 ;
  while (temp -> next != NULL ) {
    temp = temp -> next ;
  }
  temp2  = temp -> prev ;
  temp2 -> next = NULL ;
  free(temp) ;
  return head ;
}

int main( ) {

  struct node *head  =NULL   ;

  head  = addempty(head  , 5) ;
  head  = add_at_end(head, 10) ;
  head  = add_at_end (head ,90) ;
  struct node *ptr  = head ;
  while (ptr != NULL ) {
    printf ("%d" , ptr  -> data) ;
    ptr  = ptr  -> next ;
  }
  printf("\n") ;
  return  0 ;
}

