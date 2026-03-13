#include <stdio.h>

#define MAX 5

int cq[MAX];
int front = -1, rear = -1;

void insert(int value)
{
    if((front == 0 && rear == MAX-1) || (rear + 1 == front))
    {
        printf("Circular Queue Overflow\n");
        return;
    }

    if(front == -1)
        front = rear = 0;
    else if(rear == MAX - 1)
        rear = 0;
    else
        rear++;

    cq[rear] = value;
}

void delete()
{
    if(front == -1)
    {
        printf("Circular Queue Underflow\n");
        return;
    }

    printf("Deleted element: %d\n", cq[front]);

    if(front == rear)
        front = rear = -1;
    else if(front == MAX - 1)
        front = 0;
    else
        front++;
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Elements are:\n");
    i = front;

    while(1)
    {
        printf("%d ", cq[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}