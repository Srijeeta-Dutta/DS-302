#include<stdio.h>
#include<stdlib.h>
typedef struct stud
{
    int info;
    struct stud *next_link;
}Node;
Node *start= NULL;
int add_Node(int data)
{
    Node *newNode=NULL,*ptr;
    newNode=(Node*)malloc(sizeof(Node));
    newNode->info=data;
    newNode->next_link=NULL;
    if(start==NULL)
    {
        start=newNode;
    }
    else
    {
        ptr=start;
        while (ptr->next_link!=NULL)
        {
            ptr=ptr->next_link;
        }
        ptr->next_link=newNode;
    }
}
void display()
{
    Node *ptr;
    ptr=start;
    while (ptr)
    {
        printf("%d->",ptr->info);
        ptr=ptr->next_link;
    }
    printf("NULL\n");
}
void search()
{
    Node *ptr;
    ptr=start;
    printf("Enter the value you want to search in the Linked List\n");
    int val;
    scanf("%d",&val);
    while (ptr)
    {
        if(ptr->info==val)
        {
            printf("The value %d was found in the Linked lis\n",val);
        }
        ptr=ptr->next_link;
    }
    
}
int main()
{
    int data;
    char user_choice;
    while(1)
    {
        printf("Want to add then press y/Y\n");
        scanf("%c",&user_choice);
        if(user_choice=='y'||user_choice=='Y')
        {
            printf("Enter the value \n");
            scanf("%d",&data);
            add_Node(data);
            fflush(stdin);
        }
        else
        {
            break;
        }
    }
    display();
    search();
}