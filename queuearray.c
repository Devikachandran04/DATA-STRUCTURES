#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int size, front = -1, rear = -1;
int *a;
void createQueue(int s) {
    size = s;
   a = malloc(sizeof(size));
}
bool isEmpty() {
    if (front == -1)
        return true;
    else
        return false;
}

bool isFull() {
    if (rear == size - 1)
        return true;
    else
        return false;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full\n");
    } else {
        if (front == -1 && rear == -1) {
            front = 0;
        }
        rear = rear + 1;
        a[rear] = item;
    }
}
int dequeue() {
    int item = 0;
    if (isEmpty()) {
        printf("Queue Underflow\n");
    } else {
        item = a[front];
        if (front == rear) {
            rear = front = -1;
        } else {
            front = front + 1;
        }
    }
    return item;
}

void display() {
    
        for (int i = front; i <= rear; i++) {
            printf("%d ", a[i]);
        }
        
    
}

int main() {
    int s;
    printf("Enter the size of Queue:");
    scanf("%d", &s);
    createQueue(s);
    
    int item, ch;
    bool k;
    while (1) {
        printf("\nEnter Choice:\n1: Enqueue\n2: Dequeue\n3: Is Empty\n4: Is Full\n5: Display\n"); // Added "Exit" option
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the number to insert:");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                item = dequeue();
                if (!isEmpty()) {
                    printf("Item deleted is %d\n", item);
                }
                break;
            case 3:
                k = isEmpty();
                if (k == true)
                    printf("Queue is Empty\n");
                else
                    printf("Not Empty\n");
                break;
            case 4:
                k = isFull();
                if (k == true)
                    printf("Queue is Full\n");
                else
                    printf("Not Full\n");
                break;
            case 5:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}
