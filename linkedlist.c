//Singly linked list


#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int value;
    struct node *link;
} node;
node* createhead() {
    node* head;
    head = malloc(sizeof(node));
    head->link = NULL;
    return head;
}
node* createnode() {
    node* newnode;
    newnode = malloc(sizeof(node));
    return newnode;
}

void insertfirst(node* head, int data) {
    node* newnode = createnode();
    newnode->value = data;
    if (head->link == NULL) {
        head->link = newnode;
        newnode->link = NULL;
    } else {
        newnode->link = head->link;
        head->link = newnode;
    }
}

void insertlast(node* head, int data) {
    node* newnode = createnode();
    newnode->value = data;

    if (head->link == NULL) {
        head->link = newnode;
        newnode->link = NULL;
    } else {
        node* current = head->link;
        while (current->link != NULL) {
            current = current->link;
        }
        current->link = newnode;
        newnode->link = NULL;
    }
}
void deletefirst(node* head) {
    node* current;
    if (head->link == NULL) {
        printf("List Empty\n");
    } else {
        current = head->link;
        head->link = current->link;
    }
}
void deletelast(node* head) {
    node* current, *prev;
    if (head->link == NULL) {
        printf("List Empty\n");
    } else {
        current = head->link;
        prev = head;
        while (current->link != NULL) {
            prev = current;
            current = current->link;
        }
        prev->link = NULL;
    }
}

void display(node* head) {
    node* current = head->link;
    while (current != NULL) {
            printf("%d -> ", current->value);
            current = current->link;
        }
    }
void search(node* head,int key)
{
    node* current=head->link;
    while(current!=NULL)
    {
        if(key==current->value)
        {
            printf("Element found");
            break;
        }
        else
            printf("Element not found");
            break;
        current=current->link;
    }
}
void main()
{
    struct node* head=createhead();
    int ch,key,num;
    while(1)
    {
   printf("\n\t\t MENU DRIVEN \n\n");
    printf("1.insertfirst\n");
    printf("2.insertlast\n");
    printf("3.deletefirst\n");
    printf("4.deletelast\n");
    printf("5.Search\n");
    printf("6.display\n");
    printf("\n enter choice:\n");
    scanf("%d",&ch);
    switch(ch)
    {
       case 1: printf("Enter the number to be inserted:\n");
          scanf("%d",&num);
          insertfirst(head,num);
          break;
       
       case 2: printf("Enter the number to be inserted:\n");
          scanf("%d",&num);
          insertlast(head,num);
          break;

       case 3: deletefirst(head);
          display(head);
          break;

       case 4: deletelast(head);
          display(head);
          break;

       case 5: printf("\nEnter the element to be searched:");
          scanf("%d",&key);
          search(head,key);
          break;
       
       case 6: display(head);
          break;
       default: printf("Invalid choice\n");
        exit(0);
                break;
             
    }
    }
}