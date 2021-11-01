#include <stdio.h>
#include <stdlib.h>
typedef struct stud
{
    int size;
    int top;
    int *arr;
} stack;
stack *stack_pointer;
int isEmpty(stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int isFull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
        return 0;
}
void push(int val)
{
    stack *sp=stack_pointer;
    if (isFull(sp)==1)
    {
        printf("Stack Overflow");
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = val;
    }
}
int pop()
{
    stack *sp = stack_pointer;
    if (isEmpty(sp)==1)
    {
        printf("Stack is underflow!");
    }
    else
    {
        int val = sp->arr[sp->top];
        sp->top--;
        return val;
    }
}
int main()
{
    stack_pointer = (stack *)malloc(sizeof(stack));
    printf("Enter the size of your stack which you want\n");
    scanf("%d", &stack_pointer->size);
    stack_pointer->arr = (int *)malloc(stack_pointer->size * sizeof(int));
    printf("The stack was successfully created\n");
    int choice, data;
    while (1)
    {
        printf("Press 1 for Push\n2 for pop\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Enter you data\n");
            scanf("%d", &data);
            push( data);
        }
        else if (choice == 2)
        {
            int return_val = pop();
            printf("Value popped is %d", return_val);
        }
        else
        {
            break;
        }
    }
}