#include <stdio.h>

int binarysearch(int a[], int n, int key) {
    int mid, low = 0, high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == key) {
            return mid; 
        } else if (a[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; 
}
void bubblesort(int a[], int n) {
    int i, j, temp, flag;
    for (i = 0; i < n - 1; i++) {  
        flag = 0;  
        for (j = 0; j < n - 1 ; j++) {  
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break; 
        }
    }
}
void main() {
    int n;
    printf("Enter size of the array:");
    scanf("%d", &n);
    int a[n], i;
    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Enter element to be searched:");
    int k;
    scanf("%d", &k);
    bubblesort(a, n);
    int index = binarysearch(a, n, k);
    if (index != -1)
        printf("Element found using Binary Search\n");
    else
        printf("Element not found using Binary Search\n");
}
 