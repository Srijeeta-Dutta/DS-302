#include<stdio.h>
#include<stdlib.h>
typedef struct stud
{
    int front,rear,size;
    int *arr;
}Queue;
Queue *queue_pointer;
int isEmpty()
{
    if(queue_pointer->rear==queue_pointer->front)
    {
        return 1;
    }
    else
    return 0;
}
int isFull()
{
    if((queue_pointer->rear+1)%queue_pointer->size==queue_pointer->front)
    {
        return 1;
    }
    else
    return 0;
}
void enquqe(int data)
{
    if(isFull()==1)
    {
        printf("This Queue is full\n");
    }
    else
    {
        queue_pointer->rear=(queue_pointer->rear+1)%queue_pointer->size;
        queue_pointer->arr[queue_pointer->rear]=data;
        printf("Item Enqueued\n");
    }
}
int Dequeue()
{
    if(isEmpty()==1)
    {
        printf("The Queue is Empty\n");
    }
    else
    {
        queue_pointer->front=(queue_pointer->front+1)%(queue_pointer->size);
        int val = queue_pointer->arr[queue_pointer->front];
        return val;
    }
}
void display(int count)
{
    printf("printing queue elements\n");
    for (int i = 1; i <=count; i++)
    {
        printf("%d ",queue_pointer->arr[i]);
    }
    
}
int main()
{
    queue_pointer=(Queue*)malloc(sizeof(Queue));
    queue_pointer->front=queue_pointer->rear=0;
    queue_pointer->size=10;
    queue_pointer->arr=(int*)malloc(queue_pointer->size*sizeof(int));
    int choice=0,data,ret_val=0;
    int count=0;
    while (choice!=4)
    {
        printf("\nPress\n1 for Enqueu\n2 for Dequeue\n3 for Display\n4 to exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter your data to Enqueu\n");
            scanf("%d",&data);
            enquqe(data);
            count++;
            break;
        case 2:
            ret_val=Dequeue();
            printf("Item Dqueue is %d\n",ret_val);
            count--;
            break;
        case 3:
        display(count);
        break;
        default:
        printf("Wrong Choice\n");
            break;
        }
    }
    
}
