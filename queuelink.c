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
void enqueue(node* head, int data) {
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
void dequeue(node* head) {
    node* current;
    if (head->link == NULL) {
        printf("Queue Empty\n");
    } else {
        current = head->link;
        head->link = current->link;
       }
}
void display(node* head) {
    node* current = head->link;
    while (current != NULL) {
            printf("%d -> ", current->value);
            current = current->link;
        }
 }
int main() {
    node* head = createhead();
    int ch, num;
    while (1) {
        printf("\nMENU \n\n");
        printf("1. enqueue\n2. dequeue\n3. Display\n");
        printf("Enter Choice:");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the number to be inserted:\n");
                scanf("%d", &num);
                enqueue(head, num);
                display(head);
                break;
            case 2:
                dequeue(head);
                display(head);
                break;
            case 3:
                display(head);
                break;
            default:
                printf("Invalid choice\n");
                exit(0);
        }
    }
    return 0;
}
