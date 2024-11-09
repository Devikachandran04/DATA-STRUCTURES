// Pgm for BFS

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int *Q,V[10];
int front=-1, rear=-1;
int size;
int G[10][10],V[10],n;
void createqueue(int s)
{
	size=s;
	Q=malloc(size * sizeof(int));
}
bool isempty()
{
	if(front==rear)
		return true;
	else
		return false;
}
bool isfull()
{
	if(rear==size-1)
		return true;
	else
		return false;
}
int enqueue(int item)
{
	if(isfull())
		printf("\nQueue Overflow\n");
	else
		Q[++rear]=item;
}
int dequeue()
{
	if(isempty())
		return 1;
	else
		return Q[++front];
}
void bfs(int i)
{
  int j;
  V[i]=1;
  enqueue(i);
  while(!(isempty()))
  {
     i=dequeue();
     printf(" %d\n ",i);
     for(j=0;j<n;j++)
        if(!V[j]&&G[i][j]==1)
        {
           V[j]=1;
           enqueue(j);
        }
  }
}
void main()
{
  int i,j;
  printf("\nEnter the number of vertices : \n");
  scanf("%d",&n);
  createqueue(n);
  printf("\nEnter the adjecency matrix of the graph : \n");
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
      printf("\nIs edge present %d -> %d ? : ",i,j);
      scanf("%d",&G[i][j]);
    }
  for(i=0;i<n;i++)
    V[i]=0;
  printf("\n");  
  bfs(0);
  printf("\n");
}