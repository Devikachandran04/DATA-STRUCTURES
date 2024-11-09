#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int *stack;
int top=-1;
int size;

void createstack(int s)
{
	size=s;
	stack=malloc(sizeof(size));
	
}
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
	
}
int isfull()
{
	if(top==size-1)
		return 1;
	else
		return 0;
	
}
void push(int item)
{
	if(isfull())
		printf("stack is full");
	else
		stack[++top]=item;
	
}
int pop()
{
	if(top==-1)
		printf("stack empty");
	else
		return stack[top--];
	
}
int postfixevaluation(char a[100])
{
	int len=strlen(a);
	int i=0,j=0;
	int e,d;
	createstack(len);
	while(a[i]!='\0')
	{
		char t=a[i];
		
		if(t=='+')
		{
			e=pop();
			d=pop();
			push(d+e);
			
		}
		else if(t=='-')
		{
			e=pop();
			d=pop();
			push(d-e);
			
		}
		else if(t=='*')
		{
			e=pop();
			d=pop();
			push(d*e);
			
		}
		else if(t=='/')
		{
			e=pop();
			d=pop();
			push(d/e);
			
		}
		else
		{
			e=t-'0';
			push(e);
		}
		i++;
	}
	e=pop();
	return e;
			
}
void main()
{
	
	printf("enter the postfix expression:");
	char input[100];
    scanf("%s",input);
	int output=postfixevaluation(input);
	printf("%d",output);
		
}