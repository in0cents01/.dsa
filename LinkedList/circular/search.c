// concept for search 
// element   ,   index    
// node *temp  = tail -> next 
// do {
// if (temp  -> data   == element ) {
// return index  ; 
// }
// temp  = temp  -> next 
// index++ ; 
// } while (temp != tail  -> next) ;  
// return -1 ;  

#include <stdio.h> 
#include <stdlib.h> 
 
struct node {
  int data ; 
  struct node *next ; 
} ;   
struct node *atEmpty(int data) {
  struct node *temp = (struct node*)malloc(sizeof(struct node)) ; 
  temp -> data = data  ; 
  temp  -> next  = temp ; 
  return temp ; 
} 
struct node *atEnd(struct node *tail , int data) {
  struct node *temp = (struct node*)malloc(sizeof(struct node)) ; 
  temp -> data  = data ; 
  temp  -> next  = NULL ; 
  temp  -> next  = tail  -> next ; 
  tail  -> next  = temp ; 
  tail  = tail  -> next ; 
  return tail ; 
}
 
void printlist(struct node *tail ) {
  struct node *newptr  = tail  -> next ; 
  if (tail == NULL) return  ; 
  do {
    printf("%d->", newptr  -> data) ; 
    newptr  = newptr  ->next ; 
  } while (newptr != tail  -> next) ; 
}
int search(struct node *tail  , int element ) {

  struct node *temp   ; 
  int index  = 0 ; 
  if (tail == NULL) return -2 ; 
  temp  = tail  -> next ; 
  do {
    if (temp  -> data  == element ) return index ; 
    temp  = temp  -> next ;  
    index++ ; 
  }while (temp != tail  -> next)  ; 
  return -1 ; 
}
int main() {
 
  struct node *tail  = NULL ; 
  int element ; 
  tail  = atEmpty(5) ; 
  tail  = atEnd (tail , 45); 
  tail  = atEnd (tail , 65) ; 
  tail  = atEnd (tail , 90) ; 
  printlist(tail) ;  
  printf ("\n") ; 
  printf("Enter the Element : ") ; 
  scanf("%d"  , &element) ; 
  int index  = search(tail , element ) ; 
  if (index  == -1) printf("not found !") ; 
  else if (index  == -2) printf ("list is empty !") ; 
  else   printf("Element %d  is  at index %d :   "  ,  element , index ) ;
  return  0; 
}
