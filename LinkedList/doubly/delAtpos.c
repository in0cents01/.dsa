//concept idea
// while (pos > 1 )
// temp = temp -> next ;
// pos --
// temp2 = temp -> prev
// temp2 -> next  = temp  -> next
// temp  -> next  -> prev  = temp2
// free(temp)
// temp = NULL


#include <stdio.h>
#include <stdlib.h>

struct  node {
  struct node *prev;
  int data ;
  struct node *next ;
} ;
struct node  *addempty(struct node *head , int data)  {
  struct node *temp  = (struct node*)malloc(sizeof(struct node)) ;
  temp  -> prev  = NULL ;
  temp -> data  = data ;
  temp  -> next = NULL ;
  return temp ;
}
struct node *add_atend(struct node *head  , int data) {

  struct node *temp  = (struct node*)malloc(sizeof(struct node)) ;
  temp  -> prev  = NULL ;
  temp -> data  = data ;
  temp  -> next = NULL ;

  struct node *curr  = head ;
  while (curr -> next != NULL ) {
    curr  = curr -> next ;
  }
  curr -> next  = temp  ;
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
struct node* deletPos(struct node *head , int pos ) {

  struct node *temp  = head ;
  struct node *temp2  = NULL ;

  if (temp == 1) {
    head = del_firstnode(head);
    return head ;
  }

  while (pos > 1) {
    temp  = temp -> next ;
    pos-- ;
  }
  if (temp -> next == NULL ) {
    head  =  del_lastNode(head) ;
  }else {
    temp2 =  temp  -> prev ;
    temp2  -> next  =temp  -> next ;
    temp -> next -> prev  = temp2 ;
    free(temp) ;
    temp = NULL ;
  }
  return head ;
}
int main() {
  struct node *head = NULL  ;
  head  = addempty(head  , 10 ) ;
  head  = add_atend(head , 34) ;
  head  = add_atend(head  , 95) ;
  int pos = 2 ;
  head   = deletPos(head  ,pos) ;

  struct node *ptr = head ;
  while (ptr != NULL) {
    printf("%d"  , ptr  -> data  ) ;
    ptr  = ptr  -> next ;
  }
  printf("\n") ;


  return  0 ;
}