// Polynomial Addition

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int coeff,degree;
struct node *link;
} node;
node* createhead()
{
node *head;
head= malloc(sizeof(node));
head->link=NULL;
return head;
}
node* createnode()
{
node *newnode;
newnode=malloc(sizeof(node));
return newnode;
}
void insertlast(node *head,int c,int d)
{
node *newnode=createnode();
newnode->coeff=c;
newnode->degree=d;
if(head->link==NULL)
{
head->link=newnode;
newnode->link=NULL;
}
else
{
node *current;
current=head->link;
while(current->link!=NULL)
current=current->link;
current->link=newnode;
newnode->link=NULL;
}
}
void addpoly(node *head1,node *head2,node *head3)
{
node *current1,*current2;
int coe;
current1 = head1->link;
current2 = head2->link;
while((current1!=NULL)&&(current2!=NULL))
{
if((current1->degree)>(current2->degree))
{
insertlast(head3,current1->coeff,current1->degree);
current1 = current1->link;
}
else if((current1->degree)<(current2->degree))
{
insertlast(head3,current2->coeff,current2->degree);
current2 = current2->link;
}
else
{
coe = current1->coeff + current2->coeff;
insertlast(head3,coe,current2->degree);
current1 = current1->link;
current2 = current2->link;
}
}
while(current1!=NULL)
{
insertlast(head3,current1->coeff,current1->degree);
current1 = current1->link;
}
while(current2!=NULL)
{
insertlast(head3,current2->coeff,current2->degree);
current2 = current2->link;
}
}
void displaysum(node *head)
{
node *current=head->link;
printf("\nFinal Sum of the polynomials =");
while(current!=NULL)
{
printf(" %dx^%d ",current->coeff,current->degree);
printf("+");
current=current->link;
}
}
void display(node *head)
{
node *current=head->link;
printf("Input polynomial =");
while(current!=NULL)
{
printf(" %dx^%d ",current->coeff,current->degree);
printf("+");
current=current->link;
}
}
void main()
{
struct node *head1=createhead();
struct node *head2=createhead();
struct node *head3=createhead();
int n,c,d,i;
printf("Polynomial-1\n");
printf("Enter the number of terms:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("Enter the coefficient:");
scanf("%d",&c);
printf("Enter the degree:");
scanf("%d",&d);
insertlast(head1,c,d);
}
display(head1);
printf("\nPolynomial-2\n");
printf("Enter the number of terms:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("Enter the coefficient:");
scanf("%d",&c);
printf("Enter the degree:");
scanf("%d",&d);
insertlast(head2,c,d);
}
display(head2);
addpoly(head1,head2,head3);
displaysum(head3);
}