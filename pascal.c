#include<stdio.h>
int m[101][101];
void pascal()
{
  // row 1
  m[1][1] = 1;
 
  //row 2
  m[2][1] = 1;
  m[2][2] = 1;
 
  int i,j;
  for(i=3;i<101;i++)
  {
    m[i][1] = 1;
    m[i][i] = 1;
    for(j=2;j<i;j++)
    {
      m[i][j] = m[i-1][j-1] + m[i-1][j];
    }
  }
}

void print(int n)
{
  int i,j;
  for(i=1;i<=n;i++)
  {
     for(j=1;j<=i;j++)
       printf("%d ",m[i][j]);
     printf("\n");
  }
}
int main()
{
  int n;
  scanf("%d",&n);
  pascal();
  print(n); //print pascal 
  return n;
}
