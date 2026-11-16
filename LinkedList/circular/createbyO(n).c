 

#include <stdlib.h> 
#include <stdio.h> 
  
struct node {

  int data ; 
  struct node *next ;  
} ;
  
struct node *atEmpty(int data) {
  struct node *temp   = (struct node*)malloc(sizeof(struct node)) ; 
  temp -> data = data ; 
  temp  -> next  = temp ; 
  return temp ; 
} 
struct node *atEnd(struct node *tail , int data) {

  struct node *newp  = (struct node*)malloc(sizeof(struct node)) ; 
  newp  -> data  = data ; 
  newp  -> next  = NULL ; 
  if (tail  == NULL) return  0   ; 
  newp  -> next  = tail -> next ; 
  tail  -> next  = newp ; 
  tail  = tail -> next ; 
  return tail ; 
}
struct node *createList(struct node *tail) {
  int n  , data ; 
  printf("Enter the number of node  of the linked list  : ") ;  
  scanf("%d"  , &n) ;  
  if (n == 0 ) return  tail ; 
  printf ("Enter the Element : ") ;
  scanf ("%d"  , &data) ;
  tail  = atEmpty(data) ; 
  for (int i  =1 ; i< n ; ++i) {
    printf("Enter the Element %d : " , i+1) ; 
    scanf ("%d"  , &data ) ;   
    tail  = atEnd(tail  , data ) ;  
  } 
  return tail ;  
} 
void printlist(struct node *tail ) {
  struct node *ptr  = tail -> next ; 
  if (tail  == NULL ) return ; 
  do {
    printf (" %d ->" , ptr  -> data) ;  
    ptr  = ptr  -> next ; 
  } while (ptr != tail -> next ) ;
  printf ("\n");  
}
int main() { 

  struct node *tail  = NULL   ;  
  tail  =  createList(tail) ;  
  printlist(tail) ; 
  return  0 ;
}

