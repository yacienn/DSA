#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
typedef struct Node {
    int data ;
    struct Node* next ;
}Node ;
Node *head = NULL ;
Node *last = NULL ;
Node *create(){
    int n ;
    printf("input a number : ");
    scanf("%i", &n); 
    while (n != 0){
      int d = n % 10 ;
      Node* newnode = (Node*)malloc(sizeof(Node));
      newnode->data=d ;
      if (head == NULL){
        head= newnode ; last = newnode ; newnode->next = newnode ;
      }else{
        last->next=newnode ; newnode->next=head ; last = last->next ;
      } n = n / 10 ;
    }return head ;
}
 void insertAtB(){
  int d ; printf("\n Enter a new val : "); scanf("%d" , &d );
   Node* newnode = (Node*)malloc(sizeof(Node));
      newnode->data=d ;
      if (head == NULL){
        head= newnode ; last = newnode ; newnode->next = newnode ;
      }else{
         newnode->next=head ; head = newnode ; last->next= head; ;
      }
 }
 void insertAtE(){
   int d ; printf("\n Enter a new val : "); scanf("%d" , &d );
   Node* newnode = (Node*)malloc(sizeof(Node));
      newnode->data=d ;
      if (head == NULL){
        head= newnode ; last = newnode ; newnode->next = newnode ;
      }else{
         last->next=newnode ; newnode->next=head ; last = last->next ;
      }
 }
  void value (){
    int v2 , v1 ; bool found = false ; Node* current = head ;
    printf("\n enter V2 : ");  scanf("%i", &v2);
    printf("\n enter v1 : ");  scanf("%i", &v1);
    Node* newnode = (Node*)malloc(sizeof(Node)); 
    newnode->data=v2 ; newnode->next= NULL ;
    while (current->next != head){
          if ( current->data == v1){
            found = true ;
             newnode->next=current->next;
             current->next=newnode ;
          }current=current->next ;
    } 
    if (current->next==head && current->next->data == v1){
      current->next=newnode ; last=newnode ; last->next=head ; found = true ;
    }if (found == false) printf("value 1 not founded !!!!");    

  }
void display(){
  Node* current = head ;
  do{
    printf("[%i] -> " , current->data);
    current=current->next;
  }while (current != head);
   printf("//NULL");
}
int main (){
 Node *list = create();
 display();
  insertAtB();
display();
insertAtE();
display();
value();
display();
return 0; 
}