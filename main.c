#include <stdio.h>
#include <stdlib.h>

typedef struct node{
char data[50];
struct node *next;
}Node;

void insert_node(char *);
void insert_beginning(char*);
void delete_node(char*);
void delete_beginning();
void delete_end();
void print_list();
void count_list();
void sortlist();


Node *head=NULL;
Node *ptr=NULL;
int main()
{
  char value_to_delete[50];
    print_list();
//inserting random values to the linked list to test
     int i=0;
    while( i<5){
        char input[50];
        printf("enter the value: ");
        scanf("\n%[^\n]s",input);
        insert_node(input);
        i++;
    }

    count_list();
    print_list();
    //deleting node from the list
  /*  printf("enter the value to be deleted from the list: ");
    scanf("\n%[^\n]s",value_to_delete);
    delete_node(value_to_delete);
    count_list();
    print_list();
    //insert in the beginning
    puts("******************************************");
    char begin_var[50];
    printf("enter the value to add in the beginning: ");
    scanf("\n%[^\n]s",begin_var);
    insert_beginning(begin_var);
    count_list();
    print_list();
    //delete from the beginning
    puts("******************************************");
    puts("deleting the first node");
    delete_beginning();
    count_list();
    print_list();
    puts("******************************************");
    puts("deleting the last node");
    delete_end();
    count_list();
    print_list();
    */
    puts("******************************************");
    puts("sorting the list");
    sort();
    print_list();
    return 0;
}


void insert_node(char *value){
Node *newNode , *last;
newNode=(Node *)malloc(sizeof(Node));
strcpy(newNode->data ,value);
if (head == NULL){
    head = newNode;
    newNode->next = NULL;
}
else {
        last = head;
    while(last->next !=NULL){
        last = last->next;
    }
    last->next = newNode;
    newNode->next = NULL;
}
}


void print_list(){
Node *currentNode = NULL;
if (head == NULL){
    printf("the linked list is empty\n");
}
else{
currentNode = head;
while(currentNode != NULL){
   printf("%s \n",currentNode->data);
    currentNode=currentNode->next;
}
}
}


void delete_node(char *value){
Node *current, *previous;
current = head;
previous = head;

int no_value = 1;
while(current != NULL){
    if (strcmp(current->data , value) ==0){
     no_value = 0;
     break;
    }
    current = current->next;
}
if (no_value == 1){
    printf("the list is not containing the value: %s\n",value);
    return;
}
current = head;
previous = head;

if (strcmp(current->data , value) ==0){
    head = current->next;
    free(current);
    return;
}
while( strcmp(current->data , value)!=0){
    previous = current;
    current = current->next;
}
previous->next = current->next;
free(current);
printf("the value %s deleted from the list\n",value);
}

void insert_beginning(char *value){
Node *new_node = (Node *)malloc(sizeof(Node *));
strcpy(new_node->data , value);
new_node->next = head;
head=new_node;
}

void delete_beginning(){
    if (head == NULL){
        printf("the linked list is empty.\n");
    }
    else {
        Node *first_node = head;
        head = first_node->next;
        free(first_node);
    }

}


void count_list(){
int count=0;
if (head == NULL){
    printf("the linked list is empty\n");
}
Node *ptr = NULL;
ptr=head;
while(ptr != NULL){
    count++;
    ptr=ptr->next;
}
printf("the linked list have %d element\n",count);
}


void delete_end(){
if (head == NULL){
    puts("the linked list is empty ");
}

else if (head->next == NULL){
    free(head);
    head = NULL;
}

else {
    Node *ptr = head;
    while (ptr->next->next != NULL){
       ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
}
}

void sort(void)
    {
     int strcmp(char [],char []);
     int i;
     char temp[20],s1[20],s2[20];
     Node *ptr2;
     for(ptr=head;ptr!=NULL;ptr=ptr->next)
       {
     for(ptr2=ptr->next;ptr2!=NULL;ptr2=ptr2->next)
       {
     strcpy(s1,ptr->data);
     strcpy(s2,ptr2->data);
     i=strcmp(s1,s2);
     if(i==1)
       {
    strcpy(temp,ptr->data);
    strcpy(ptr->data,ptr2->data);
    strcpy(ptr2->data,temp);
    }
    }
      }
     }
