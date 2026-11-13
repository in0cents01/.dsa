#include <stdio.h> 
#include <stdlib.h> 
 
// head -> link   = NULL ;  
// temp  -> link = head ; 
// temp2 -> link  = temp ;  
// head  -- end  
//
// temp  =  NULL ; 
// temp2  = NULL ; 
struct node  {

  int data ; 
  struct node *link ;
} ; 
static void add_at_end(struct node *head  , int data) {

  struct node *temp  = (struct node*)malloc(sizeof(struct node)) ;  
  temp  -> data = data ; 
  temp  -> link  = NULL ; 
   
  struct node *curr  = head ; 
  while (curr -> link != NULL ) {
 
    curr = curr-> link ;  
  } 
  curr  -> link  = temp ; 
} 
struct node* reverse(struct node *head ) {
 
  struct node *prev  = NULL ; 
  struct node *next  = NULL ; 
  while(head != NULL) {
    next  = head -> link; 
    head  ->link  = prev ; 
    prev  = head ; 
    head  = next ; 
  } 
  head  = prev ; 
  return head ; 
}
int main() {
  
  struct node *head  = (struct node*)malloc(sizeof(struct node)) ;  
  head  -> data = 10 ;  
  head  -> link  = NULL ; 
  add_at_end(head , 20 ) ; 
  add_at_end(head ,30 ) ;  
  head  = reverse(head) ; 
  struct node *ptr  = head ; 
  while (ptr != NULL ) {
    printf("%d\t" , ptr -> data ) ; 
    ptr  = ptr  -> link ; 
  } 
  printf("\n"); 
  return  0 ;
}
