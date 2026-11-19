#include <stdio.h> 
#include <stdlib.h> 


struct node {
 
  int data ; 
  struct node *next ; 
} ; 
struct node *atEmpty(int data) {

  struct node *temp = (struct node*)malloc(sizeof(struct node)) ;  
  temp  -> data  = data ;  
  temp  -> next  = temp ;  
  return temp; 
} 
struct node *atEnd(struct node *head , int data) {
 
  struct node *newp  = (struct node*)malloc(sizeof(struct node)) ;
  newp  -> data  = data ;

  newp  -> next  = head  -> next ;
  head  -> next  = newp ; 
  head  = head  -> next ; 
  return head ; 
}  
struct node *insert(struct node *head  , int data) {

  struct node *newp   = (struct node*)malloc(sizeof(struct node)) ;
  newp  -> data  = data ;

  if (head == NULL) {
    newp -> next = newp ;
    return newp ;
  }

  if (data < head -> next -> data) {          /* new first node */
    newp -> next = head -> next ;
    head -> next = newp ;
    return head ;
  }

  struct node *temp = head -> next ;
  while (temp -> next != head -> next && temp -> next -> data < data)
    temp = temp -> next ;

  newp -> next = temp -> next ;
  temp -> next = newp ;

  if (temp == head)                            /* new last node */
    head = newp ;

  return head ;
}
void printlist(struct node *head) {

  struct node *temp ;

  if (head == NULL) {
    printf("\n") ;
    return ;
  }

  temp = head -> next ;
  do {
    printf("%d->" , temp -> data) ;
    temp = temp -> next ;
  } while (temp != head -> next) ;
  printf("\n") ;
}

int main() {
   
  struct node *head  = NULL ; 
  head  = atEmpty(10) ; 
  head = atEnd(head  , 35) ; 
  head = atEnd(head  , 90) ; 
  head = atEnd(head  , 100) ;
  printlist(head) ;

  head = insert(head , 5) ;
  head = insert(head , 50) ;
  head = insert(head , 1000) ;
  printlist(head) ;

  return  0  ;
}
