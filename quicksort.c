//QUICK SORT PROGRAM

#include<stdio.h>
#include<stdlib.h>
int *arr;
int pi,i,s;

int partition(int arr[],int low,int high)
{
    int i,pivot;
    pivot=arr[high];
    i=low-1;
    int j,k;
    for(j=low;j<=high-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            
            k=arr[i];
            arr[i]=arr[j];
            arr[j]=k;
        }
    }
k=arr[i+1];
arr[i+1]=arr[high];
arr[high]=k;
return(i+1);
}

void quickSort(int arr[],int low,int high)
{
    if(low<high)
    {
        pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
     }
 }
 
int main()
{
    printf("Enter the size of array:");
    scanf("%d",&s);
    arr=malloc(sizeof(s));
    printf("Enter array elements\n");
    for(i=0;i<s;i++)
    {
        scanf("%d",&arr[i]);
    }
    quickSort(arr,0,s-1);
    printf("Sorted array: \n");
    for(i=0;i<s;i++)
    {
        printf("%d ",arr[i]);
    }    
    return 0;
}