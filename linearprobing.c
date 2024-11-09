#include<stdio.h>
#include<stdlib.h>
int a[100];

void insert(int key, int s) {
    int index = key % s;
    if (a[index] == 0) {
        a[index] = key;
        printf("%d inserted\n", key);
    } else {
        int i = index, flag = 0;
        do {
            if (a[i] == 0) {
                a[i] = key;
                printf("%d inserted\n", key);
                flag = 1;
                break;
            }
            i = (i + 1) % s;
        } while (i != index);  // Changed condition here

        if (flag == 0) {
            printf("Hash Table is full\n");
            exit(0);
        }
    }
}

void delete(int key,int s)
{
for(int i=0;i<s;i++)
{
if(a[i]==key)
{
a[i]=0;
printf("%d deleted",key);
}
}
}
void display(int s)
{
    for(int i=0;i<s;i++)
    {
        if(a[i]==0)
        {
            printf("_\t");
        }
        else
       {
            printf("%d\t",a[i]);
        }
    }
}

void search(int key, int s)
{
int index= key%s;
if(a[index]==key)
{
printf("%d found at %d",key,index+1);
}
else
{
int i=index, flag=0;
        do
        {
        if(a[i]==key)
        {
        printf("%d found at position %d",key,index+1);
        flag=1;
        break;
        }
        i=(i+1)%s;
        } while(i!=index);
        if (flag==0)
        {
        printf("Key not found");
        }
}
}

void main()
{
        int key;
        int ch,s;
        printf("Enter the size of hash table: ");
        scanf("%d",&s);
        for(int i=0;i<s;i++)
        {
            a[i]=0;
        }
        while(1)
        {
        printf("\nMenu\n1. Linear Probing\n2. Delete\n3. Search\n4. Display\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter key value: ");
            scanf("%d",&key);
            insert(key,s);
            break;
           
            case 2:
            printf("Enter the value to be deleted: ");
            scanf("%d",&key);
            delete(key,s);
            break;
           
            case 3:
            printf("Enter the value to be searched: ");
            scanf("%d",&key);
            search(key,s);
            break;
           
            case 4:
                display(s);
                break;
            default:
                printf("Enter valid option");
                     
        }
    }

}