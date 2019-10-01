#include <stdio.h>
#include <stdlib.h>


struct node {
  int data;
  struct node *ptr;
}*front=NULL, *rear=NULL, *t;

void insert(int ele){

  t = (struct node *)malloc( sizeof(struct node) );
  if(t==NULL){
    printf("OVERFLOW!!");
  }
  else if(rear==NULL){
    rear = front = t;
    t->data = ele;
    t->ptr = NULL;
  }
  else{
    rear->ptr = t;
    rear = t;
    t->data = ele;
    t->ptr = NULL;
  }
}

void delete(){
  if(front==NULL){
    printf("UNDERFLOW!!");
  }
  else if(front == rear){
    printf("%d\n", front->data);
    free(front);
    front = rear = NULL;
  }
  else{
    t = front;
    printf("%d\n", t->data);
    front = front->ptr;
    free(t);
  }
}

void display(){
  for(t=front; t!=NULL; t=t->ptr){
    printf("%d\n", t->data);
  }
}


void main(){
  int choice;
  do
  {
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1:{
        for(int i=1; i<9; i++){
          insert(i);
        break;
        }
      }
      case 2:{
        delete(); break;
      }
      case 3:{
        display(); break;
      }
      case 4:{printf("---------------------------\n");printf("Exiting...\n");printf("---------------------------\n");

              exit(0);
              }
      default:{printf("---------------------------\n"); printf("ERROR!\n"); printf("---------------------------\n");}
    }
  }while(choice>0 && choice<6);

}
