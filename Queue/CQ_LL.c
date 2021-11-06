#include<stdio.h>
#include<stdlib.h>
typedef struct CQ_LL
{
    int info;
    struct CQ_LL *next;
}CQueue ;
CQueue *front=NULL;
CQueue *rear=NULL;
void enQueue(int data)
{
    CQueue *newNode=(CQueue*)malloc(sizeof(CQueue));
    if (newNode==NULL)
    {
        printf("Queue is full\n");
    }
    else
    {
        newNode->info=data;
        newNode->next=NULL;
        if(front==NULL)
        {
            front=rear=newNode;
        }
        else
        {
            rear->next=newNode;
            rear=newNode;
        }
    }
    printf("Item Added\n");
}
int deQueue()
{
    CQueue *ptr=front;
    if(front==NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        front=front->next;
      int  val=ptr->info;
        return val;
        free(ptr);

    }
}
void display()
{
    CQueue *ptr=front;
    while (ptr)
    {
        printf("%d->",ptr->info);
        ptr=ptr->next;
    }
    
}
int main()
{
    int choice =0,data,ret_val;
    while (choice !=4)
    {
        printf("\nPress\n1 for Enqueue\n2 for Dequeue\n3 for Display\n4 to exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        printf("Enter the data which you want to Enqueue\n");
            scanf("%d",&data);
            enQueue(data);
            break;
        case 2:
        ret_val=deQueue();
        printf("Item dequeue is %d\n",ret_val);
        break;
        case 3:
        display();
        break;
        case 4:
        break;
        default:
        printf("Wrong Choice\n");
            break;
        }
    }
    
}