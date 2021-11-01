#include<stdio.h>
#include<stdlib.h>
typedef struct stud
{
    struct stud *lptr;
    struct stud *rptr;
    int info;
}Node;
Node *start=NULL, *last=NULL;
void add_Node(int data)
{
    Node *newNode=NULL, *tptr=NULL;
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
 Node*ptr;
 ptr=start;
 while (ptr)
 {
     printf("%d->",ptr->info);
    ptr=ptr->rptr;
 }
 printf("NULL");
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
void delete_atBeg()
{
    Node *ptr=start;
    start=start->rptr;
    start->lptr=NULL;
    free(ptr);
}
void delete_atEnd()
{
    Node *ptr=start;
    Node *tptr=start->rptr;
    while (tptr->rptr!=NULL)
    {
        ptr=ptr->rptr;
        tptr=tptr->rptr;
    }
    ptr->rptr=NULL;
    last=ptr;
    free(tptr);
    
}
int main()
{
    int data;
    char user_choice;
    while (1)
    {
        printf("Press y to insert data\n");
        scanf("%c",&user_choice);
        if(user_choice=='y'|| user_choice=='Y')
        {
            printf("Enter you data\n ");
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
    printf("\n");
    display_Backword();
    // printf("\nDeleting the beg node\n");
    // delete_atBeg();
    // display_forward();
    // printf("\n");
    // display_Backword();
      printf("Deleting at end node \n");
        delete_atEnd();
        //display_forward();
       // printf("\n");
        display_Backword();
}