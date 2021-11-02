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
        printf("Stack Overflow!!! cannot push anymore");
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
        printf("Stack is underflow!cannot pop anymore \n");
    }
    else
    {
        int val = sp->arr[sp->top];
        sp->top--;
        return val;
    }
}
int peek(int index)
{
    stack *sp=stack_pointer;
    int arrayIndex;
    arrayIndex=sp->top-index+1;
   if(arrayIndex < 0)
    {
        printf("Not a valid position");
        return -1;
    }
    else
    {
        return sp->arr[arrayIndex];
    }
}
 int main()
{
    stack_pointer = (stack *)malloc(sizeof(stack));
    stack_pointer->top=-1;
    printf("Enter the size of your stack which you want\n");
    scanf("%d", &stack_pointer->size);
    stack_pointer->arr = (int *)malloc(stack_pointer->size * sizeof(int));
    printf("The stack was successfully created\n");
    int choice, data;
    stack *sp=stack_pointer;
    while (1)
    {
        printf("Press 1 for Push\n2 for pop\n3 for priniting values\n");
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
            printf("Value popped is %d\n", return_val);
        }
        else if(choice==3)
        {
            for (int i=1; i <=sp->top+1; i++)
            {
                printf("The value at position %d is %d\n",i,peek(i));
            }
            
        }
        else
        {
            break;
            exit(0);
        }
    }
}