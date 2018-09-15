#include<stdio.h>
#define MAX_SIZE 5

typedef struct
{
    int top;
    int data[MAX_SIZE];
} Stack;

void push(Stack *s, int input);
void pop(Stack *s);
void display(Stack *s);

int main()
{
    Stack mStack;
    int choice;

    mStack.top = -1;

    while(printf("Press 1 to push\npress 2 to pop\npress 3 to display\n") && scanf("%d", &choice) != EOF)
    {
        switch(choice)
        {
        case 1:
            if(mStack.top >= MAX_SIZE-1)
            {
                printf("Stack is full or overflow\n\n");
            }
            else
            {
                int input;
                printf("Enter a number for push\n");
                scanf("%d", &input);
                push(&mStack, input);
                printf("%d pushed\n\n", input);
            }
            break;

        case 2:
            if(mStack.top < 0)
            {
                printf("Stack underflow or empty\n\n");
            }
            else
            {
                pop(&mStack);
            }
            break;

        case 3:
            display(&mStack);
            break;

        default:
            printf("Invalid option choose\n\n");
        }
    }

    return 0;
}

void push(Stack *s, int input)
{
    s->top++;
    s->data[s->top] = input;
}

void pop(Stack *s)
{
    printf("%d Poped\n\n", s->data[s->top]);
    s->top--;
}

void display(Stack *s)
{
    int i;
    if(s->top < 0)
    {
        printf("Stack empty\n\n");
    }
    else
    {
        printf("Stack: ");
        for(i=0; i<=s->top; i++)
        {
            printf("%d ", s->data[i]);
        }
        printf("\n\n");
    }
}


