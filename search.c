#include<stdio.h>

void linearsearch(int a[], int size, int key)
{
    int i, flag = 0;
    for(i = 0; i < size; i++)
    {
        if(a[i] == key)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
        printf("Element found using linear search\n");
    else
        printf("Element not found using linear search\n");
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
    printf("Enter element to be searched:");
    int k;
    scanf("%d", &k);
    linearsearch(a, n, k);     
}
