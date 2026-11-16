// need pos for list node 
// create p  for new node  
// p = tail  -> next 
// while (pos > 1 ) 
// p  = p -> next ; 
// pos-- ;  
// newp   -> next  = p -> next  
// p  -> next  = newp ;
//
//
// time O(n) 
#include <stdio.h> 
#include <stdlib.h> 
 

struct node  {

  int data ; 
  struct node *next ;  

}  ; 
 
struct node *atEmpty(int data) {
 
  struct node *temp  = (struct node*)malloc(sizeof(struct node)) ; 
  temp -> data  = data ; 
  temp  -> next = temp ; 
  return temp ; 
} 
struct node *atEnd(struct node *tail , int data ) {
 
  struct node *newp  = (struct node*)malloc(sizeof(struct node)) ; 
  newp  -> data  = data ; 
  newp  -> next  = NULL  ; 
  newp  -> next  = tail -> next ; 
  tail  -> next  = newp ; 
  tail  = tail  -> next ;   
  return tail ; 
} 
struct node *atPos(struct node *tail , int data , int pos ) {
 
  struct node *p  = tail -> next  ; 
  struct node *newp   = (struct node*)malloc(sizeof(struct node)) ;  
  newp  -> data   = data ; 
  newp  -> next  = NULL ; 
  while (pos > 1) {
     p  =  p -> next ;
    pos-- ; 
  } 
  newp  -> next = p  -> next ; 
  p  -> next  = newp  ; 
  if (p  == tail ) {
    tail  = tail -> next ;  
  } 
  return tail ; 
} 
void printlist(struct node *tail){
  struct node *ptr  = tail -> next ;
            if (tail == NULL) return  ;
  do {
     printf(" %d -> "  , ptr  -> data ) ; 
    ptr  = ptr -> next ; 
  }while (ptr != tail -> next) ; 
  printf("\n") ;
} 

int main() {
 
  struct node *tail = (struct node*)malloc(sizeof(struct node)) ;  
  tail  = atEmpty(34)  ;  
  int pos  = 2;  
  tail = atEnd( tail , 45) ; 
  tail  = atEnd (tail  , 6) ; 
  tail  =atPos(tail , 66 , pos) ; 
  printlist(tail) ; 
  return  0 ; 
}
