#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void insert(int value)
{
    if(rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        if(front == -1)
            front = 0;

        rear++;
        queue[rear] = value;
    }
}

void delete()
{
    if(front == -1 || front > rear)
        printf("Queue Underflow\n");
    else
    {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}

void display()
{
    int i;

    if(front == -1 || front > rear)
        printf("Queue is empty\n");
    else
    {
        printf("Queue elements:\n");
        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
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