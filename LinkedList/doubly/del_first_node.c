//concept idea
// head  = head -> next
// free(temp)
//temp = NULL
// head -> prev = NULL ;


#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *prev ;
  int data ;
  struct node *next ;
} ;
struct node* addempty (struct node *head  , int data ) {

  struct node *temp  = (struct node*) malloc(sizeof(struct node)) ;
  temp  -> prev = NULL ;
  temp  -> data  = data ;
  temp  -> next  = NULL ;
  return temp ;
}
struct node *add_at_end(struct node *head , int data) {


  struct node *temp = (struct node*)malloc(sizeof(struct node)) ;
  temp  -> prev  = NULL ;
  temp  -> data  = data ;
  temp  -> next  = NULL ;
  struct  node *curr  = head;
  while (curr -> next != NULL ) {
    curr  = curr  -> next ;
  }
  curr -> next  = temp ;
  temp  -> prev  = curr ;
  return head ;
}
struct node *del_firstnode(struct node *head ) {


  struct node *temp  = head;
  head  = head  -> next ;
  free(temp) ;
  temp  = NULL ;
  head -> prev  = NULL;
  return head ;

}
int main() {


  struct node *head  = NULL ;
  head   = addempty(head  , 5) ;
  head   = add_at_end(head  , 10) ;

  head  = del_firstnode(head) ;
  struct node *ptr  = head ;
  while (ptr != NULL) {
    printf("%d"  , ptr  -> data ) ;
    ptr  = ptr  -> next ;
  }
  printf("\n") ;

  return  0 ;
}