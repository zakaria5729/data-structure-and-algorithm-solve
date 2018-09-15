#include<stdio.h>
#define MAX_SIZE 5

void push(int Input);
void pop();
void display();

int Top = -1;
int Stack[MAX_SIZE];
int Input;

int main()
{
    int choice;

    while(printf("Press 1 to push\npress 2 to pop\npress 3 to display\n") && scanf("%d", &choice) != EOF)
    {
        switch(choice)
        {
        case 1:
            if(Top >= MAX_SIZE-1)
            {
                printf("Stack overflow or full\n\n");
            }
            else
            {
                printf("Enter a number for push\n");
                scanf("%d", &Input);
                push(Input);
                printf("%d pushed\n\n", Input);
            }
            break;

        case 2:
            if(Top < 0)
            {
                printf("Stack underflow or empty\n\n");
            }
            else
            {
                pop();
            }
            break;

        case 3:
            display();
            break;

        default:
            printf("Invalid option choose\n\n");
        }
    }

    return 0;
}

void push(int Input)
{
    Stack[++Top] = Input;
}

void pop()
{
    printf("%d Poped\n\n", Stack[Top]);
    Top--;
}

void display()
{
    int i;
    if(Top < 0)
    {
        printf("Stack empty\n\n");
    }
    else
    {
        printf("Stack: ");
        for(i=0; i<=Top; i++)
        {
            printf("%d ", Stack[i]);
        }
        printf("\n\n");
    }
}
