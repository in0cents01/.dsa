#include <stdio.h> 
#include <stdlib.h> 
 
struct node {
  struct node *prev ; 
  int data ; 
  struct node *link ; 
} ; 
struct node *addToempty(struct node *head   , int data ) {

  struct node *temp  =malloc(sizeof(struct node)) ;   
  if (temp == NULL ) return head ; 
  temp  -> prev  = NULL ; 
  temp  -> data  = data ; 
  temp -> link  = NULL ;  
  return temp ; 
}
int main() { 
  struct node *head  =  NULL  ;  
  head  = addToempty(head , 10) ;  
  printf("%d", head  -> data );  
  free(head) ; 
  return  0 ; 
} 
