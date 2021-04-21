#include <stdio.h>
#include <stdlib.h>

typedef struct node{
int data;
struct node *next;
}Node;

void insert_node(int);
void print_list();
void delete_node(int);


Node *head=NULL;

int main()
{
  int value_to_delete;
    print_list();

     int i=0;
    while( i<=5){
        int input;
        printf("enter the value: ");
        scanf("%d",&input);
        insert_node(input);
        i++;
    }
    print_list();
    printf("enter the value to be deleted from the list: ");
    scanf("%d ",&value_to_delete);
    delete_node(value_to_delete);
    print_list();

    return 0;
}

void insert_node(int value){
Node *newNode , *last;
newNode=(Node *)malloc(sizeof(Node));
newNode->data=value;
if (head == NULL){
    head = newNode;
    newNode->next = NULL;
}
else {
        last = head;
    while(last->next !=NULL){
        last = last->next;
    }
    last->next=newNode;
    newNode->next=NULL;
}

}

void print_list(){
Node *currentNode=NULL;
if (head==NULL){
    printf("the linked list is empty\n");
}
else{
currentNode=head;
while(currentNode !=NULL){
   printf("%d \n",currentNode->data);
    currentNode=currentNode->next;
}
}
}

void delete_node(int value){
Node *current, *previous;
current = head;
previous = head;

int no_value=1;
while(current->next != NULL){
    if (current->data == value){
     no_value=0;
     break;
    }
    current=current->next;
}
if (no_value==1){
    printf("the list is not containing the value: %d",value);
    return;
}
current = head;
previous = head;

if (current->data == value){
    head = current->next;
    free(current);
    return;
}
while(current->data !=value){
    previous = current;
    current = current->next;
}
previous->next = current->next;
free(current);
printf("the value %d deleted from the list\n",value);
}
