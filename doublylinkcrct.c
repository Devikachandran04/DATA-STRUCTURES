#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* prev;
    struct node* next;
} node;

// Function to create the head of the doubly linked list
node* createHead() {
    node* head;
    head = malloc(sizeof(node));
    head->next = NULL;
    head->prev = NULL;
    return head;
}

// Function to create a new node
node* createNode() {
    node* newnode;
    newnode = malloc(sizeof(node));
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

// Function to insert at the beginning (InsertFirst)
void insertFirst(node* head, int data) {
    node* newnode = createNode();
    newnode->value = data;

    if (head->next == NULL) {
        head->next = newnode;
        newnode->prev = head;
    } else {
        newnode->next = head->next;
        newnode->prev = head;
        head->next->prev = newnode;
        head->next = newnode;
    }
}

// Function to insert at the end (InsertLast)
void insertLast(node* head, int data) {
    node* newnode = createNode();
    newnode->value = data;

    if (head->next == NULL) {
        head->next = newnode;
        newnode->prev = head;
    } else {
        node* current = head->next;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
        newnode->prev = current;
    }
}

// Function to delete the first node (DeleteFirst)
void deleteFirst(node* head) {
    if (head->next == NULL) {
        printf("List is empty\n");
    } else {
        node* temp = head->next;
        if (temp->next == NULL) {
            head->next = NULL;
        } else {
            head->next = temp->next;
            temp->next->prev = head;
        }
        free(temp);
        printf("First node deleted\n");
    }
}

// Function to delete the last node (DeleteLast)
void deleteLast(node* head) {
    if (head->next == NULL) {
        printf("List is empty\n");
    } else {
        node* current = head->next;
        while (current->next != NULL) {
            current = current->next;
        }
        if (current->prev == head) {
            head->next = NULL;
        } else {
            current->prev->next = NULL;
        }
        free(current);
        printf("Last node deleted\n");
    }
}

// Function to display the list
void display(node* head) {
    node* current = head->next;
    if (current == NULL) {
        printf("List is empty\n");
    } else {
        while (current != NULL) {
            printf("%d <-> ", current->value);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Function to search for a value in the list
void search(node* head, int key) {
    node* current = head->next;
    while (current != NULL) {
        if (current->value == key) {
            printf("Element %d found in the list.\n", key);
            return;
        }
        current = current->next;
    }
    printf("Element %d not found in the list.\n", key);
}

// Main function to test the doubly linked list
int main() {
    node* head = createHead();
    int choice, num, key;

    while (1) {
        printf("\n\t\t MENU DRIVEN \n\n");
        printf("1. InsertFirst\n");
        printf("2. InsertLast\n");
        printf("3. DeleteFirst\n");
        printf("4. DeleteLast\n");
        printf("5. Search\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to be inserted at the beginning: ");
                scanf("%d", &num);
                insertFirst(head, num);
                break;

            case 2:
                printf("Enter the number to be inserted at the end: ");
                scanf("%d", &num);
                insertLast(head, num);
                break;

            case 3:
                deleteFirst(head);
                display(head);
                break;

            case 4:
                deleteLast(head);
                display(head);
                break;

            case 5:
                printf("Enter the element to be searched: ");
                scanf("%d", &key);
                search(head, key);
                break;

            case 6:
                display(head);
                break;

            case 7:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
