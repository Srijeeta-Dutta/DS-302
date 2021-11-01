#include<stdio.h>
#include<stdlib.h>
typedef struct stud
{
    int info;
    struct stud *lptr;
    struct stud *rptr;
}Node;
Node *start=NULL, *last=NULL;
void add_Node(int data)
{
    Node *newNode=NULL,*tptr=NULL;
    newNode=(Node*)malloc(sizeof(Node));
    newNode->info=data;
    newNode->lptr=NULL;
    newNode->rptr=NULL;
    if(start==NULL)
    {
        start=newNode;
    }
    else
    {
        tptr=start;
        while (tptr->rptr!=NULL)
        {
            tptr=tptr->rptr;
        }
        tptr->rptr=newNode;
        newNode->lptr=tptr;
        last=newNode;
    }
}
void display_forward()
{
    printf("Displying Forward\n");
    Node *tptr=start;
    while (tptr)
    {
        printf("%d ->",tptr->info);
        tptr=tptr->rptr;
    }
    printf("NULL\n");
}
void display_backword()
{
    printf("Displaying backword\n");
    Node *tptr=last;
    while (tptr)
    {
        printf("%d->",tptr->info);
        tptr=tptr->lptr;
    }
    printf("NULL");
}
void searching()
{
    Node*ptr=start;
    printf("\nEnter the value which you want to seearch in the List\n");
    int key;
    scanf("%d",&key);
    while (ptr)
    {
        if(key==ptr->info)
        {
            printf("The value was found");
            break;
        }
        ptr=ptr->rptr;
    }
    

}
int main()
{
    int data;
    char user_choice;
    while (1)
    {
        printf("Press y/Y to enter a New Node\n");
        scanf("%c",&user_choice);
        if(user_choice=='Y'||user_choice=='y')
        {
            printf("Enter you value\n");
            scanf("%d",&data);
            add_Node(data);
            fflush(stdin);
        }
        else
        {
            break;
        }
    }
    display_forward();
    display_backword();
    searching();
}