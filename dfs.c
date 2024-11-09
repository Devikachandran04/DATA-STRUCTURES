#include<stdio.h>
int G[10][10],V[10],n;
void dfs(int i)
{
  int j;
  printf("\n%d ",i);
  V[i]=1;
  for(j=0;j<n;j++)
    if(!V[j]&&G[i][j]==1)
       dfs(j);
}
void main()
{
  int i,j;
  printf("\nEnter the number of vertices : \n");
  scanf("%d",&n);
  printf("\nEnter the adjecency matrix of the graph : \n");
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
      printf("\nIs edge present %d -> %d ? : ",i,j);
      scanf("%d",&G[i][j]);
    }
  for(i=0;i<n;i++)
    V[i]=0;
  dfs(1);
  printf("\n");
}
