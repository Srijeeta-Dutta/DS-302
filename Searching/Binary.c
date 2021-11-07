#include<stdio.h>
#include<stdlib.h>
int array_Input(int *arr, int n) 
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the %d element-> ",i+1);
        scanf("%d",&arr[i]);
    }
    return *arr;
}
int print_Array(int *arr,int n) 
{
   for (int i = 0; i < n; i++)
    {
        printf("Printing the %d element-> %d\n",i,arr[i]);
    
    }   
}
int binary_Search(int *arr,int size,int key)
{
    int LB,UB,MID;
    LB=0;
    UB=size-1;
    while(LB<=UB)
    {
        MID=(LB+UB)/2;
        if(arr[MID]==key)
        {
            printf("The elemnt %d has been found at %d index",arr[MID],MID);
            return 0;
        }
        else if(arr[MID]<key)
        {
            LB=MID+1;
        }
        else{
            UB=MID-1;
        }

    }
    printf("Element was not found");

}
int main()
{
    int *arr,n,key;
    arr=(int *)malloc(n*sizeof(int));
    printf("Enter the Number of elements you want\n");
    scanf("%d",&n);
    array_Input(arr,n);
    printf("Enter the value which you want to search\n");
    scanf("%d",&key);
    binary_Search(arr,n,key);

}