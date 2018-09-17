#include<stdio.h>

typedef struct node Node;
struct node
{
    int data;
    Node *next;
};

Node *head = NULL, *new_node, *trail, *start, *prev_node;

int main()
{
    int choice, num, value, position;

    while(1)
    {
        printf("\t1.Create\n\t2.First Insert\n\t3.Last Insert\n\t4.nth position Insert\n\t5.Update\n\t6.Delete\n\t7.Display\n\t0.Exit\nEnter your option: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Enter the number of node: ");
            scanf("%d", &num);
            create(num);
            break;

        case 2:
            first_insert();
            break;

        case 3:
            last_insert();
            break;

        case 4:
            printf("Enter a value and a position?\n");
            scanf("%d%d", &value, &position);
            nth_position_insert(value, position);
            break;

        case 5:
            printf("Enter the value which you want to update?\n");
            scanf("%d", &value);
            update(value);
            break;

        case 6:
            printf("Enter the value which you want to delete?\n");
            scanf("%d", &value);
            delete(value);
            break;

        case 7:
            display();
            break;

        case 0:
            exit(1);
            break;

        default:
            printf("Invalid option selected! Please select right option..\n\n");
        }
    }

    return 0;
}

void create(int num)
{
    int i;

    for(i=0; i<num; i++)
    {
        new_node = (Node*) malloc(sizeof(Node*));

        printf("Enter a value for %dth node\n", i+1);
        scanf("%d", &new_node->data);

        if(new_node == NULL)
        {
            printf("Error! Could not create a new node.\n");
            return;
        }

        if(head == NULL)
        {
            head = new_node;
        }
        else
        {
            trail->next = new_node;
        }
        trail = new_node;
    }
    trail->next = NULL;

    printf("Node created successfully\n\n");
}

void first_insert()
{
    if(head == NULL)
    {
        printf("Please create at least a single node first.\n\n");
    }
    else
    {
        new_node = (Node*) malloc(sizeof(Node*));

        printf("Enter a value for first insert: ");
        scanf("%d", &new_node->data);

        if(new_node == NULL)
        {
            printf("Error! Could not create a new node.\n");
            return;
        }

        new_node->next = head;
        head = new_node;

        printf("Node inserted at first position\n\n");
    }
}

void last_insert()
{
    if(head == NULL)
    {
        printf("Please create at least a single node first.\n\n");
    }
    else
    {
        new_node = (Node*) malloc(sizeof(Node*));

        printf("Enter a value for last insert: ");
        scanf("%d", &new_node->data);

        if(new_node == NULL)
        {
            printf("Error! Could not create a new node.\n\n");
            return;
        }

        start = head;
        while(start->next != NULL)
        {
            start = start->next;
        }
        start->next = new_node;
        new_node->next = NULL;

        printf("Node inserted at last position\n\n");
    }
}

void nth_position_insert(int value, int position)
{
    start = head;
    int distance_from_head = 1;

    while(start != NULL)
    {
        if(distance_from_head == position)
        {
            break;
        }
        else
        {
            distance_from_head++;
        }

        prev_node = start;
        start = start->next;
    }

    if(distance_from_head != position)
    {
        printf("Your entered position is not available\n\n");
        return;
    }

    new_node = (Node*)malloc(sizeof(Node));

    if(new_node == NULL)
    {
        printf("Error! Could not create a new node.\n\n");
        return;
    }

    new_node->data = value;
    prev_node->next = new_node;
    new_node->next = start;

    printf("Node inserted at nth position\n\n");
}

void update(int value)
{
    start = head;

    while(start != NULL)
    {
        if(start->data == value)
        {
            printf("Enter a new value for update: ");
            scanf("%d", &start->data);
            printf("Your value is updated.\n\n");
            return;
        }
        start = start->next;
    }
    printf("Your entered value is not found.\n\n");
}

void delete(int value)
{
    start = head;

    while(start != NULL)
    {
        if(head->data == value)
        {
            head = head->next;
            printf("Your entered value is deleted\n\n");
            break;
        }
        if(start->data == value)
        {
            prev_node->next = prev_node->next->next;
            printf("Your entered value is deleted\n\n");
            break;
        }
        else
        {
            if(start == NULL)
            {
                printf("Your entered value is not found.\n\n");
                break;
            }
            prev_node = start;
            start = start->next;
        }
    }
}

void display()
{
    start = head;

    while(start != NULL)
    {
        printf("%d->", start->data);
        start = start->next;
    }
    printf("NULL\n\n");
}

