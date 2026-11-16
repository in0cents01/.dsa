 
// concept idea 
// newp  -> next  = tail ->  next 
// tail  -> next  = newp ;  
// O(1)

#include <stdlib.h> 
#include <stdio.h> 

struct node {
  int data ; 
  struct node *next ;  
} ;  
struct node *atEmpty (int data ) {
 
  struct node *temp  = (struct node*)malloc(sizeof(struct node)) ;  
  temp  -> data  = data ; 
  temp  -> next  = temp  ;
  return temp ; 
} 
struct node *atBegin(struct node *tail  , int data) {
  struct node *newp = (struct node*)malloc(sizeof(struct node)) ;  
  newp  -> data  = data ; 
  newp  -> next  = tail -> next ; 
  tail  -> next  = newp ; 
  return tail ; 
}  
void print(struct node *tail) {
  struct node *ptr  = tail -> next ; 
  if (tail  == NULL ) return   ; 
  do {
    printf("%d ->" ,  ptr  -> data ) ;  
    ptr  = ptr  -> next ;  
  } while (ptr != tail -> next )  ;  

}
int main() {
  struct node *tail  ;   
  tail  = atEmpty(45) ;  
  tail  = atBegin(tail  , 10) ;
  tail  = atBegin(tail , 50) ; 
  print(tail) ; 
  return  0 ; 
}
