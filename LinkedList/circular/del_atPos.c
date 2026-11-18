//concept  timeO(n)  ; 
// node *temp = tail  -> next ; 
// whiel (pos > 2) {
// temp  = temp  -> next ; 
// pos-- ; 
// } 
// snode *temp 2 ; 
// temp2  = temp  -> next ; 
// temp -> next   = temp2 -> next ; 
// free(temp2) ; 
// temp2 = NULL ; 

#include <stdio.h>
#include <stdlib.h> 
 
struct node {
  int data ; 
  struct node *next ;
}  ;
 
struct node *atEmpty(int data) {
  struct node *temp  = (struct node*)malloc(sizeof(struct node)) ;   
  temp  -> data  = data  ; 
  temp  -> next  = temp ;  
  return temp ;  
}  
struct node *atEnd(struct node *tail , int data) {
  struct node *newp  = (struct node*)malloc(sizeof(struct node)) ; 
  newp  -> data  = data ; 
  newp  -> next  = NULL ;  
  newp  -> next  = tail  -> next ; 
  tail  -> next  = newp ; 
  tail  = tail  -> next ; 
  return tail ; 
}  
  
struct node *del_atPos(struct node *tail   , int pos) {
  if (tail  == NULL) return tail ;  
  struct node *temp  = tail  -> next ; 
  if (tail  -> next == tail) {
    free(tail)  ;
    tail  = NULL ; 
    return tail ;  
  } 
  while (pos > 2) {
    temp  = temp -> next ; 
    pos-- ; 
  } 
  struct node *temp2 = temp  -> next ; 
  temp -> next  = temp2 -> next ;  
  if (temp2  == tail) tail  = temp ; 
  free(temp2) ; 
  temp2  = NULL ; 
  return tail ; 
}
void printlist(struct node *tail ) {
  struct node *ptr  = tail  -> next ; 
  if (tail  == NULL) return  ; 
  do {
    printf("%d->" , ptr -> data);  
    ptr  = ptr  -> next ;  
  } while (ptr != tail  -> next) ; 
}
struct node *createList(struct node *tail) {
  int n  ,  data ; 
  printf("Enter the number of list : ") ; 
  scanf("%d" , &n) ; 
  printf("Enter the Element : ") ; 
  scanf("%d" , &data); 
  tail  = atEmpty(data) ; 
  for (int i  =1 ; i< n  ; ++i) {
    printf("Enter the Element  %d :  "  ,i+1) ; 
    scanf("%d" , &data) ; 
    tail  = atEnd(tail , data) ; 
  } 
  return tail  ; 
}
int main() {
  
  int pos = 2 ; 
  struct node *tail   = NULL; 
  tail  = createList(tail) ; 
  tail  = del_atPos(tail  , pos) ;
  printlist(tail) ;   

  return  0 ; 
}
