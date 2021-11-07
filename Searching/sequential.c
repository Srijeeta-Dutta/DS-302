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
int linear_Search(int *arr,int size, int element) 
{
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element)
        {
            printf("The elemen %d was found in the Array at %d index",arr[i],i);
            return 0;
        }
    
    }   

    printf("The element was not found in the Array");
}
int main()
{
    int *arr;
    int n,ele;
    printf("Enter the Number of Elemets you want \n");
    scanf("%d",&n);
    array_Input(arr,n);

   // print_Array(arr,n);

    printf("Enter the element which You want to be search\n");
    scanf("%d",&ele);
    linear_Search(arr,n,ele);


}