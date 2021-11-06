#include <stdio.h>
#include <stdlib.h>
typedef struct stud
{
    int data;
    struct stud *next;
} Queue;
Queue *front, *rear;
void enque()
{
    Queue *node;
    node = (Queue *)malloc(sizeof(Queue));
    int val;
    if (node == NULL)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter your data\n");
        scanf("%d", &val);
        node->data = val;
        if (front == NULL)
        {
            front = rear = node;
            front->next = NULL;
            rear->next = NULL;
        }
        else
        {
            rear->next = node;
            rear=node;
            rear->next = NULL;
        }
    }
}
int deque()
{
    Queue *ptr;
    int val;
    if (front == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        ptr = front;
        val = ptr->data;
        front = front->next;
        return val;
        free(ptr);
    }
}
void display()
{
    Queue *ptr;
    ptr = front;
    if (front == NULL)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        printf("printing values\n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}
int main()
{
    int choice = 0;
    while (choice != 4)
    {
        printf("\nPress\n1 for Enqueue\n2 for Dequeue\n3 for Display\n4 for exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enque();
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Wrong Choice\n");
            break;
        }
    }
}