#include <stdio.h>
int merge(int arr[], int l, int m, int r)
{
   int i, j, k;
   int b[50];
    
    i = l; 
    j = m+1; 
    k = l; 
    while (i <=m && j <= r) {
        if (arr[i] <= arr[j]) {
            b[k] = arr[i];
            i++;
        }
        else {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
  
   
    if(i>m)
    {
	
    while (j <= r) {
        b[k] = arr[j];
        j++;
        k++;
    }
}
  
   
    else{
	
    while (i <= m) {
        b[k] = arr[i];
        i++;
        k++;
    }
}
for(k=l;k<=r;k++)
{
	arr[k]=b[k];
}
return 0;
}
  

int mergeSort(int arr[], int l, int r)
{
    if (l < r) {
       
        int m = l + (r - l) / 2;
  
        
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
  
        merge(arr, l, m, r);
    }
    return 0;
}
  



int main()
{
    
int arr[50],n,i;

  printf("Enter size of the list: ");
  scanf("%d",&n);

  printf("Enter the values: ",n);
  for(i = 0; i < n; i++)
    scanf("%d",&arr[i]);

  mergeSort(arr,0,n-1);

  printf("Array after sorting is: ");
  for(i = 0; i < n; i++)
    printf(" %d",arr[i]);

  return 0;
}