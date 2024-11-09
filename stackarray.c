#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
int top=-1;
int size;
int *a;
void createstack(int s)
{
size=s;
a=malloc(sizeof(size));
}
bool isempty()
{
	if(top==-1)
		return true;
	else
		return false;
}
bool isfull()
{
	if(top==size-1)
		return true;
	else
		return false;
}
void push(int item)
{
	if(isfull())
		printf("Stack Overflow");
	else
		a[++top]=item;
}
int pop()
{
	if(isempty())
		return 0;
	else
		return (a[top--]);
}
int peek()
{
	if(isempty())
		return 0;
	else
		return (a[top]);
}
void display()
{
	for(int i=top;i>=0;i--)
		printf(" %d-> ",a[i]);
}
void main()
{
int s;
printf("Enter the size of stack:");
scanf("%d",&s);
createstack(s);
int ch,item;
bool k;
while(1)
{
	printf("\nMENU \n\n");
    printf("1.Push\n2.Pop\n3.Peek\n4.Isempty\n5.Isfull\n6.Display\n");
	printf("Enter the choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("enter the number to push: ");
			scanf("%d",&item);
			push(item);
			break;
		case 2:
			item=pop();
			if(item==0)
				printf("Stack Overflow");
			else
				printf("%d is popped",item);
			break;
		case 3:
			item=peek();
			if(item==0)
				printf("Stack Overflow");
			else
				printf("%d",item);
			break;

		case 4:
			k=isempty();
			if(k==true)
				printf("Stack Underflow");
			else
				printf("Not Empty");
			break;

		case 5:
			k=isfull();
			if(k==true)
				printf("Stack Overflow");
			else
				printf("Not Full");
			break;
		case 6:
				display();
				break;
		default: exit(0);
	}
   }	
}