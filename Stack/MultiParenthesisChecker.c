#include <stdio.h>
#include <stdlib.h>
typedef struct stud
{
    int size;
    char *arr;
    int top;
} stack;
stack *stack_pointer;
int isEmptty()
{
    if (stack_pointer->top == -1)
    {
        return 1;
    }
    else
        return 0;
}
int isFull()
{
    if (stack_pointer->top == stack_pointer->size - 1)
    {
        return 1;
    }
    else
        return 0;
}
void push(char data)
{
    if (isFull(stack_pointer) == 1)
    {
        printf("Stack Overflow!!! cannot push anymore");
    }
    else
    {
        stack_pointer->top++;
        stack_pointer->arr[stack_pointer->top] = data;
    }
}
char pop()
{
    if (isEmptty(stack_pointer) == 1)
    {
        printf("Stack Underflow !! cannot pop");
    }
    else
    {
        int val = stack_pointer->arr[stack_pointer->top];
        stack_pointer->top--;
        return val;
    }
}
int parenthesisMatch(char *exp)
{

    stack_pointer = (stack *)malloc(sizeof(stack));
    stack_pointer->top = -1;
    stack_pointer->size = 100;
    stack_pointer->arr = (char *)malloc(stack_pointer->size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if ((exp[i] == ')' || exp[i] == '}' || exp[i] == ']') && isEmptty())
        {
            return 0;
        }
        else if (exp[i] == ')' && stack_pointer->arr[stack_pointer->top] == '(' || exp[i] == '}' && stack_pointer->arr[stack_pointer->top] == '{' || exp[i] == ']' && stack_pointer->arr[stack_pointer->top] == '[')
        {
            pop();
        }
    }
    if (isEmptty())
    {
        return 1;
    }
    return 0;
}
int main()
{
    char exp[100];
    printf("Enter you expression\n");
    scanf("%s", &exp);
    if (parenthesisMatch(exp) == 1)
    {
        printf("Balanced");
    }
    else
    {
        printf("Not Balanced\n");
    }
}