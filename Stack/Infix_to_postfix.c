#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stud
{
    int top;
    char *arr;
    int size;
} stack;
stack *stack_pointer;
int isEmpty()
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
    if (isFull() == 1)
    {
        printf("Stack Overflow !!! cannot push\n");
    }
    else
    {
        stack_pointer->top++;
        stack_pointer->arr[stack_pointer->top] = data;
    }
}
char pop()
{
    if (isEmpty() == 1)
    {
        printf("Stack Underflow !!cannit pop");
    }
    else
    {
        char val = stack_pointer->arr[stack_pointer->top];
        stack_pointer->top--;
        return val;
    }
}
int operatorr(char ch)
{
    if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
    {
        return 1;
    }
    else
        return 0;
}
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
char *infixtoPostfix(char *exp)
{
    stack_pointer=(stack*)malloc(sizeof(stack));
    stack_pointer->top = -1;
    stack_pointer->size = 20;
    stack_pointer->arr = (char *)malloc(stack_pointer->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(exp) + 1) * sizeof(char));
    int i = 0, j = 0;
    while (exp[i] != '\0')
    {
        if (!operatorr(exp[i]))
        {
            postfix[i] = exp[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(exp[i]) > precedence(stack_pointer->arr[stack_pointer->top]))
            {
                push(exp[i]);
                i++;
            }
            else
            {
                postfix[j] = pop();
                j++;
            }
        }
    }
    while (!isEmpty())
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{
    char *exp;
    printf("Please add your expression\n");
    scanf("%s", &exp);
    printf("The postfix is %s",infixtoPostfix(exp));
}