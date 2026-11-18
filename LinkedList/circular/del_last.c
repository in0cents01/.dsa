// concept  
// node *temp  = tail -> next     // create new  
// while(temp -> next != NULL) {
// temp   = temp  -> next ; 
// } 
// temp  -> next  = tail -> next  ; 
// free(tail) ; 
// tail  = temp ;  
// time O(n)  ; 

#include <stdio.h> 
#include <stdlib.h> 

struct node  {
  int data ; 
  struct node *next ; 
}  ;  
struct node *atEmpty(int data) {
  struct node *temp  = (struct node*)malloc(sizeof(struct node)) ;  
  temp  -> data  = data ; 
  temp  -> next  = temp ;  
  return temp ; 
} 
struct node *atEnd(struct node *tail  , int data) {
 
  struct node *newp  = (struct node*)malloc(sizeof(struct node)) ; 
  newp  -> data  = data ; 
  newp  -> next  = NULL; 
  newp  -> next = tail  -> next ; 
  tail  -> next  = newp ;  
  tail  = tail  -> next ;
  return tail  ; 
} 
struct node *createList(struct node *tail ) {
  int  n  , data  ; 
  printf("Enter the number of list : ") ;  
  scanf("%d"  , &n) ;  
  printf("Enter the Element : ") ; 
  scanf("%d"  , &data) ; 
  tail  = atEmpty(data) ; 
  for(int i  = 1 ; i<n  ; ++i) {
    printf("Enter the Element  %d : "  , i+1) ; 
    scanf("%d"  , &data) ; 
    tail = atEnd(tail  , data) ; 
  } 
  return tail ; 
} 
struct node *del_Last(struct node *tail ) {
 
  if (tail  == NULL) return tail ; 
  struct node *temp  = tail  -> next ;  
  if (tail -> next  == tail ) {
    free(tail) ;  
    tail  = NULL ;  
    return tail ; 
  } 
  while (temp  -> next  != tail ) {
    temp  = temp  -> next ; 
  } 
  temp  -> next  = tail  -> next ;  
  free(tail) ;  
  tail  = temp ; 
  return tail ; 
}
void printList(struct node *tail ) {
  struct node *ptr = tail  -> next ; 
  if (tail  == NULL) return  ;  
  do {
    printf ("%d->" , ptr  -> data) ; 
    ptr  = ptr  -> next ; 
  } while (ptr  != tail  -> next) ;  
}
int main() {
 
  struct node *tail   = NULL ; 
  tail  = createList(tail) ;  
  tail  = del_Last(tail) ; 
  printList(tail) ; 
  return  0 ; 
}
