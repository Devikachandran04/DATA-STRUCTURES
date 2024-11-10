#include <stdio.h>
#include <stdlib.h>  

int *queue; 
int front = -1, rear = -1;  
int size;  
int isFull() {
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
        return 1;  // Queue is full
    }
    return 0;  // Queue is not full
}

int isEmpty() {
    if (front == -1) {
        return 1;  // Queue is empty
    }
    return 0;  // Queue is not empty
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) {
            front = 0;  
        }
        rear = (rear + 1) % size;  
        queue[rear] = item;  
        printf("Enqueued: %d\n", item);
    }
}


int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;  
    } else {
        int temp = queue[front];
        if (front == rear) {
            front = rear = -1;  
        } else {
            front = (front + 1) % size;  
        }
        return temp;  
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i != rear; i = (i + 1) % size) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    queue = malloc(sizeof(int));
    int choice, item;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                item = dequeue();
                if (item != -1) {
                    printf("Dequeued: %d\n", item);
                }
                break;

            case 3:
                display();
                break;
        }
    }

    return 0;
}
