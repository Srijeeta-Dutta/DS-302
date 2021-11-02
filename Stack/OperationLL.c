#include <stdio.h>
#include <stdlib.h>
typedef struct stud
{
    struct stack *next;
    int info;
} stack;
stack *start = NULL;
void push()
{
    int data;
    stack *ptr = (stack *)malloc(sizeof(stack));
    if (ptr == NULL)
    {
        printf("Stack Overflow!! Cannot push anymore");
    }
    else
    {
        printf("Please enter your values\n");
        scanf("%d", &data);
        if (start == NULL)
        {
            ptr->info = data;
            ptr->next = NULL;
            start = ptr;
        }
        else
        {
            ptr->info = data;
            ptr->next = start;
            start = ptr;
        }
    }
}
void pop()
{
    int value;
    stack *ptr;
    if (start == NULL)
    {
        printf("Stack Underflow!!\n");
    }
    else
    {
        ptr = start;
        value = ptr->info;
        start = start->next;
        free(ptr);
        printf("Item popped is %d\n", value);
    }
}
void display()
{
    stack *ptr = start;
    printf("The stack elements are\n");
    while (ptr)
    {
        printf("%d->", ptr->info);
        ptr = ptr->next;
    }
    printf("NULL");
}
int main()
{
    int choice = 0;
    while (choice != 4)
    {
        printf("\nPress\n1 for Push\n2 for Pop\n3 for Display\n4 For exit");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        default:
            printf("Wrong choice\n");
            break;
        }
    }
}