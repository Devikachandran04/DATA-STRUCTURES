#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int top=-1;
int size;
int *a;
char output[100];
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
  if(top==size)
    return true;
  else
    return false;
}
void push(char item)
{
  if(isfull())
      printf("stack overflow");
  else
      a[++top]=item;
}
char pop()
{
  if(isempty())
    return '0';
  else
    return a[top--];
}
char peek()
{
  if(isempty())
    return '0';
  else
    return a[top];
}
int precedence (char p)
{
  if(p=='+'||p=='-')
    return 1;
  else if(p=='*'||p=='/')
    return 2;
  else if(p=='^')
    return 3;
  else if(p=='(')
    return 0;
}
void infix_postfix(char a[100])
  {
  int len=strlen(a);
  int i=0,j=0;
  createstack(len);
  while(a[i]!='\0')
  {
  char t=a[i];
  if(t=='(')
  push(a[i]);
  else if((t=='+')||(t=='-')||(t=='*')||(t=='/')||(t=='^'))
  {
  if(!isempty())
  {
  while(precedence(t)<=precedence(peek()))
  {
  output[j]=pop();
  j++;
  if(isempty())
    break;
  }
  }
  push(t);
  }
  else if(t==')')
  {
  while(!isempty())
  {
  char temp=pop();
  if(temp!='(')
  {
  output[j]=temp;
  j++;
  }
  else
  break;
  }
  }
  else
  {
  output[j]=t;
  j++;

  }
  i++;
  }
  while(!isempty())
  {
  output[j]=pop();
  j++;
  }
  output[j]='\0';
}

int main()
{
  char infix[100];
  int i=0;
  printf("enter the infix expression:");
  scanf("%s",infix);
  infix_postfix(infix);
  printf("\nPostfix expression:");
  i=0;
  int len=strlen(output);
  while(i<len)
  {
      printf("%c",output[i]);
      i++;
  }
  return 0;
}

