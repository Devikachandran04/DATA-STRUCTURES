#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int value;
    struct node* next;
    struct node* prev;
} node;
node* createHead() {
    node* head =malloc(sizeof(node));
    head->next = NULL;
    head->prev = NULL;
    return head;
}
node* createNode() {
    return malloc(sizeof(node));
}
void insertFirst(node* head, int data) {
    node* newnode = createNode();
    newnode->value = data;

    if (head->next == NULL) {
        head->next = newnode;
        newnode->prev = head;
        newnode->next = NULL;
    } else {
        newnode->next = head->next;
        newnode->next->prev = newnode; 
        head->next = newnode; 
        newnode->prev = head; 
    }
}
void insertLast(node* head, int data) {
    node* newnode = createNode();
    newnode->value = data;
    if (head->next == NULL) { 
        head->next = newnode;
        newnode->prev = head;
        newnode->next = NULL;
    } else {
        node* current = head->next;
        while (current->next != NULL) { 
            current = current->next;
        }
        current->next = newnode;
        newnode->prev = current;
        newnode->next = NULL;
    }
}
void deleteFirst(node* head) {
    if (head->next == NULL) {
        printf("List Empty\n");
    } else {
        node* current = head->next; 
        head->next = current->next;
        if (current->next != NULL) { 
            current->next->prev = head;
        }
    }
}
void deleteLast(node* head) {
    if (head->next == NULL) { 
        printf("List Empty\n");
    } else {
        node* current = head->next;
        while (current->next != NULL) {
            current = current->next;
        }
        if (current->prev != head) {
            current->prev->next = NULL;
        } else {
            head->next = NULL;
        }
    }
}
void display(node* head) {
    node* current = head->next;
    while (current != NULL) {
        printf("%d <-> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}
int main() {
    node* head = createHead();
    int ch, num;
    while (1) {
        printf("\nMENU \n");
        printf("1. Insert First\n2. Insert Last\n3. Delete First\n4. Delete Last\n5. Display\n");
        printf("Enter Choice:\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the number to be inserted:");
                scanf("%d", &num);
                insertFirst(head, num);
                break;
            case 2:
                printf("Enter the number to be inserted:");
                scanf("%d", &num);
                insertLast(head, num);
                break;

            case 3:
                deleteFirst(head);
                break;

            case 4:
                deleteLast(head);
                break;

            case 5:
                display(head);
                break;

            default:
                printf("Invalid choice\n");
                exit(0);
        }
    }
    return 0;
}
