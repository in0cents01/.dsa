// concept  count the  number of element  
// node *temp  = tail  -> next ; 
// int count  = 0 ; 
// while (temp != tail ) {
// count++ ; 
// temp = temp  -> next ; 
// } 
// time O(n) 

#include <stdlib.h> 
#include <stdio.h> 
struct node  {
 
  int data ; 
  struct node *next ; 
} ;  
struct node *atEmpty(int data) {
  struct node *temp  = (struct node*)malloc(sizeof(struct node)) ; 
  temp  -> data  = data ; 
  temp -> next  = temp ; 
  return temp ; 
} 
struct  node *atEnd(struct node *tail  , int data) {
  struct node *temp   = (struct node*)malloc(sizeof(struct node)) ; 
  temp  -> data  = data ; 
  temp  -> next  = NULL ; 
  temp -> next  = tail  -> next ; 
  tail  -> next  = temp ; 
  tail = tail  -> next ;  
  return tail ; 
}  
void count(struct node *tail) {
  struct node *temp  = tail  -> next ; 
  int count  = 0 ;  
  while (temp != tail) {
    temp  = temp  -> next ; 
    count++ ; 
  } 
  count++ ; 
  printf ("There are %d Element int the list  : " , count) ;  

}
void printlist(struct node *tail) {
  struct node *newptr  = tail  -> next ; 
  if (tail  == NULL ) return  ; 
  do {
    printf("%d->", newptr  -> data); 
    newptr  = newptr  -> next ; 
  }while (newptr != tail -> next) ; 
}
int main() {
 
  struct node *tail  = NULL ; 
  tail  = atEmpty(45) ; 
  tail  = atEnd(tail , 60); 
  tail  = atEnd(tail , 90); 
  count(tail) ; 
  printlist(tail) ; 
  return  0 ; 
}


