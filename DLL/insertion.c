#include<stdio.h>
#include<stdlib.h>
typedef struct stud
{
    int info;
    struct stud *lptr;
    struct stud *rptr;
}Node;
Node *start=NULL, *last=NULL;
int add_Node(int data)
{
    Node *newptr=NULL , *tptr=NULL;
    newptr=(Node*)malloc(sizeof(Node));
    newptr->info=data;
    newptr->lptr=NULL;
    newptr->rptr=NULL;
    if(start==NULL)
    {
        start=newptr;
    }
    else
    {
        tptr=start;
        while (tptr->rptr!=NULL)
        {
            tptr=tptr->rptr;
        }
        tptr->rptr=newptr;
        newptr->lptr=tptr;
        last=newptr;
        
    }
}
void display_forward()
{
  Node *tptr=start;
    while(tptr)
    {
        printf("%d->",tptr->info);
        tptr=tptr->rptr;
    }
    printf("NULL\n");
}
void display_Backword()
{
    Node *tptr=last;
    while (tptr)
    {
        printf("%d->",tptr->info);
        tptr=tptr->lptr;
    }
    printf("NULL");
}
void insertion_beg(int data)
{
    Node * newBN=NULL , *tptr=start;
    newBN=(Node*)malloc(sizeof(Node*));
    newBN->info=data;
    newBN->lptr=NULL;
    newBN->rptr=NULL;
    if(start==NULL)
    {
        start=newBN;
    }
    else
    {
        newBN->rptr=start;
        start->lptr=newBN;
        start=newBN;

    }
}
int main()
{
    int data;
    char user_Choice;
     while (1)
    {
        printf("\nDo you want to insert(y/n)?");
        scanf("%c", &user_Choice);
        if (user_Choice == 'y' || user_Choice == 'Y')
        {
            printf("\nEnter the info: ");
            scanf("%d", &data);
            add_Node(data);
            fflush(stdin);
        }
        else
        {
            break;
        }
    }
    display_forward();
    display_Backword();
    fflush(stdin);
    while(1)
    {
        printf("\nDo you want to insert in the beg(y/n)?");
        scanf("%c", &user_Choice);
        if (user_Choice == 'y' || user_Choice == 'Y')
        {
            printf("\nEnter the info: ");
            scanf("%d", &data);
            insertion_beg(data);
            fflush(stdin);
        }
        else
        {
            break;
        }
    }
     display_forward();
    display_Backword();

}