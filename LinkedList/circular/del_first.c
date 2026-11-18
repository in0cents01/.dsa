// concept for delete first node 
// struct node *temp    ;
// temp   = tail -> next ; 
// tail -> next  = temp  -> next ; 
// free(temp) 
// temp  = NULL  
// time O(1)
#include <stdio.h> 
#include <stdlib.h> 
 
struct node {
  int data ; 
  struct node *next ;   

} ; 
struct node *atEmpty(int data){

  struct node *temp = (struct node*)malloc(sizeof(struct node)) ; 
  temp  -> data  = data ; 
  temp  -> next  = temp ; 
  return temp ; 
} 
struct node  *atEnd(struct node *tail , int data) {
  struct node *newp  = (struct node*)malloc(sizeof(struct node)) ;  
  newp  -> data  = data ; 
  newp  -> next  = NULL ; 
  newp  -> next  = tail  -> next ; 
  tail  -> next   = newp ;  
  tail  = tail  -> next ;  
  return tail ; 
}  
struct node *createList(struct node* tail ) {
  int n , data ; 
  printf("Enter the number of the Linkedlist ") ; 
  scanf("%d" , &n) ;
  if (n == 0 ) return tail ;  
  printf ("Enter the Element :  ") ; 
  scanf ("%d"  , &data) ; 
  tail  = atEmpty(data) ;  
  for (int i  = 1   ; i<n ; i++) { 
    printf("Enter the Element %d : " , i+1)  ;
    scanf("%d"  , &data) ; 
    tail  = atEnd(tail  , data) ; 
  } 
  return tail ; 
}
struct node *del_atfirst (struct node *tail) {
 
  if (tail   == NULL ) return tail  ; 
  if (tail   -> next == tail ) {
    free(tail) ; 
    tail  = NULL ; 
    return tail ;  
  } 
  struct node *temp   = tail  -> next ; 
  tail  -> next  = temp -> next ; 
  free(temp)  ; 
  temp = NULL ; 
  return tail  ; 
} 
struct node *printList(struct node *tail) {
  struct node *ptr   = tail  -> next ; 
  if (tail == NULL) return 0 ;  
  do {
    printf("%d -> " , ptr  -> data) ; 
    ptr  = ptr -> next ; 
  }while ( ptr != tail  -> next   );  
}
int main() {

  struct node *tail = NULL ;  
  tail  = createList(tail)  ; 
  tail = del_atfirst(tail) ; 
  printList(tail) ; 
  return   0 ; 
}
