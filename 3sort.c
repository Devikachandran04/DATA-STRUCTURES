#include<stdio.h>
void bubblesort(int a[], int n)
{
    int i, j, temp, flag = 0;
    for(i = 0; i < n ; i++)
    {
        for(j = 0; j <n-1 ; j++)
        {
            if(a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
    printf("Bubble sort ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void selectionsort(int a[], int n)
{
    int i, j, min, temp;
    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i + 1; j <=n-1; j++)
        {
            if(a[min] > a[j])
            {
                min = j;
            }
        }
        if(min != i)
        {
            a[min]=temp;
            a[min] = a[i];
            a[i] = temp;
        }
    }
    printf("Selection SORT ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void insertionsort(int a[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++) 
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) 
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    printf("INSERTION SORT ");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
void main()
{
    int n;
    printf("Enter size of an array:");
    scanf("%d", &n);
    
    int a[n], i;
    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    bubblesort(a, n);
    selectionsort(a,n);
    insertionsort(a, n);
}