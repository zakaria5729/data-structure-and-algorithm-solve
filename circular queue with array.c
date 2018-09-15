#include<stdio.h>
#define MAX_SIZE 5

void enqueue(int input);
void dequeue();
void display();
int isFull();
int isEmpty();

int queue[MAX_SIZE];
int front = -1, rear = -1;

int main()
{
    int choice;
    int input;

    while(printf("Press 1 to enqueue\npress 2 to dequeue\npress 3 to display\n") && scanf("%d", &choice) != EOF)
    {
        switch(choice)
        {
        case 1:
            if(isFull()) {
                printf("Queue is full\n\n");
            } else {
                printf("Enter a value for enqueue: ");
                scanf("%d", &input);
                enqueue(input);
            }
            break;

        case 2:
            if(isEmpty()) {
                printf("Queue is empty\n\n");
            } else {
                dequeue();
            }
            break;

        case 3:
            if(isEmpty()) {
                printf("Queue is empty\n\n");
            } else {
                display();
            }
            break;

        default:
            printf("Invalid option choose\n\n");
        }
    }

    return 0;
}

int isFull() {
    if((rear == MAX_SIZE-1 && front == 0) || (front == rear + 1)) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if(front == -1 || rear == -1) {
        return 1;
    }
    return 0;
}

void enqueue(int input) {
    if(front == -1) {
        front = 0;
    }

    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = input;
    printf("%d enqueued\n\n", input);
}

void dequeue() {
    int element;
    element = queue[front];

    if(front == rear) {
        front = - 1;
        rear = - 1;
    }
    else {
        front = (front + 1) % MAX_SIZE;
    }

    printf("%d dequeued\n\n", element);
}

void display() {
    int i;

    printf("Queue-> ");
    for(i=front; i!=rear; i=((i+1) % MAX_SIZE)) {
        printf("%d ", queue[i]);
    }
    printf("%d\n\n", queue[i]);
}
