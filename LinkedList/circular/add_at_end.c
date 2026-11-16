// concept idea 
// newp  -> next  = tail -> next  
// tail -> next  = newp  
// tail  = tail -> next  
 
#include <stdio.h> 
#include <stdlib.h> 
 
struct node {
  int data ; 
  struct node *next ; 
} ;  
struct node* atEmpty(int data) {
  struct node *temp  = (struct node*)malloc(sizeof(struct node)) ; 
  temp  -> data  = data ; 
  temp  -> next  = temp ; 
  return temp ; 
} 
struct node *atBegin(struct node *tail  , int data) {
  struct node *newp  = (struct node*)malloc(sizeof(struct node)) ;  
  newp  -> data  = data ; 
  newp  -> next  = tail  -> next ; 
  tail -> next  = newp ;  
  return tail ; 
} 

struct node *atEnd(struct node *tail  , int data ) {
  struct node *newp  = (struct node*)malloc(sizeof(struct node));  
  newp  -> data   = data ; 
  newp  -> next  = NULL ; 
  newp  -> next  = tail -> next ; 
  tail  -> next  = newp  ; 
  tail  = tail  -> next ;  
  return tail ; 
} 
void printlist(struct node *tail) {
   
struct node *ptr  = tail -> next ; 
  if (tail  == NULL ) return ; 
  do {
 
    printf (" %d -> " , ptr  -> data ) ; 
    ptr  = ptr  -> next ; 
  }while (ptr != tail -> next)  ; 
  printf ("\n"); 
}
int main() {
 
  struct node *tail  = NULL ;   
  tail  = atEmpty(10); 
  tail  = atBegin(tail  , 24) ; 
  tail = atEnd (tail , 90) ; 
  printlist ( tail) ; 
  return  0 ; 
}
