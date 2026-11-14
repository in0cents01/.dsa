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
struct node *add_atend(struct node *head  , int data) {
  struct node *temp  = (struct node*)malloc(sizeof(struct node)) ;
  temp  -> prev  = NULL ;
  temp  -> data  = data ;
  temp  -> next  = NULL ;
  struct node *curr  = head;
  while (curr -> next != NULL ) {
    curr  = curr -> next ;
  }
  curr -> next  = temp ;
  temp  -> prev  = curr ;
  return head ;
}
struct node* reverse(struct node *head ) {
  struct node *ptr1 = head ;
  struct node *ptr2    = ptr1 -> next ;
  ptr1 -> next = NULL ;
  ptr1 -> prev  = ptr2 ;
  while (ptr2 != NULL ) {
    ptr2 -> prev  = ptr2 -> next ;
    ptr2 -> next  =  ptr1 ;
    ptr1  = ptr2 ;
    ptr2  = ptr2  -> prev ;
  }
  head  = ptr1 ;
  return head ;
}

int main() {

  struct node *head   = NULL ;
  head  = addempty(head , 10) ;
  head  = add_atend(head  , 20) ;
  head  = add_atend(head , 50) ;
  head  = reverse(head) ;
  struct node   *ptr  = head ;
  while (ptr != NULL ) {
    printf("%d"  , ptr  -> data) ;
    ptr  = ptr  -> next ;
  }
  printf("\n") ;

  return  0 ;
}