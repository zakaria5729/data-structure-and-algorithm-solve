#include<stdio.h>
#define MAX_SIZE 5

struct Queue{
    int front, rear;
    int data[MAX_SIZE+1];
};

int main()
{
    Queue circular_queue;
    circular_queue.front = 0;
    circular_queue.rear = 0;

   int item, choice;
    printf("Enter 1 for enqueue, 2 for dequeue, 3 for display\n");

    while(scanf("%d", &choice) != EOF)
    {
        switch(choice) {
            case 1:
                printf("Enter a number for enqueue\n");
                scanf("%d", &item);
                enqueue(&circular_queue, item);
                break;

            case 2:
                dequeue(&circular_queue);
                break;

            case 3:
                display(&circular_queue);
                break;

            default:
            printf("Invalid option choose. try again..\n");
        }
    }

    return 0;
}

void enqueue(Queue *q, int item) {
    if((q->rear + 1) % (MAX_SIZE + 1) == q->front) {
        printf("Queue is full\n\n");
        return;
    }

    q->data[q->rear] = item;
    printf("%d enqueued to the queue.\n\n", item);
    q->rear = (q->rear + 1) % (MAX_SIZE + 1);
}

void dequeue(Queue *q) {
    if(q->front == q->rear) {
        printf("Queue is empty\n\n");
        return;
    }

    printf("%d dequeued from the queue.\n\n", q->data[q->front]);
    q->front = (q->front + 1) % (MAX_SIZE + 1);
}

void display(Queue *q) {
    int i;

    if(q->front == q->rear) {
        printf("Queue is empty\n\n");
        return;
    }

    printf("Queue: ");
    for(i=q->front; i!=q->rear; i=((i+1) % (MAX_SIZE+1))) {
        printf("%d ", q->data[i]);
    }
    printf("\n\n");
}



