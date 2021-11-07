#include <stdio.h>
 

int insertionSort(int arr[], int n)
{
    int i, temp, j;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
 
       
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j --;
        }
        arr[j + 1] = temp;
    }
    return 0;
}
 

int printArray(int arr[], int n)
{
    int i;
    printf("The sorted array is : \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
   
    return 0;
}
 

int main()
{
	int i,n;
	printf("Enter the size of the array : ");
	scanf("%d",&n);
	int arr[n];
		printf("Enter the %d elements : \n",n);

	for (i = 0; i < n; i++)
	{
	
        scanf("%d", &arr[i]);
    }
		
	
   
    insertionSort(arr, n);
    printArray(arr, n);
 
    return 0;
}