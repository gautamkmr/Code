#include<stdio.h>
#include<stdlib.h>
int main()
{
int n=4;  
int a[4][4]={ {0,1,1,1},{1,0,1,1},{1,1,1,1},{0,1,1,1}};

int i,j,firstrow=0,firstcol=0;

    printf("\n");
 for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
     printf("%d ",a[i][j]);
    printf("\n");
  }

    printf("\n");
   
   //first check weather first column or first row has to make 0 just remember in firstrow and firstcol  
   for(i=0;i<n;i++)  //first row
    if(a[0][i]==0)
       firstrow=1;   //first row has to make 0    
   
   
   for(i=0;i<n;i++)  //first column
    if(a[i][0]==0)
     firstcol=1;     //first column has to make 0
   
   
   
for(i=1;i<n;i++)
 {
   for(j=1;j<n;j++)
    {
      if(a[i][j]==0)
       {
         a[i][0]=0;  //make first column 0   row i will be 0
         a[0][j]=0;  //make first row 0      column j will be 0  
       }                  
    }
 }
 
 //check for all column and make the entire column 0
 for(i=1;i<n;i++)
  {
     if(a[0][i]==0)
      {
        for(j=1;j<n;j++)
         a[j][i]=0;            
      }
  }
  //check for all row and make the entire row 0
  for(i=1;i<n;i++)
  {
     if(a[i][0]==0)
      {
        for(j=1;j<n;j++)
         a[i][j]=0;            
      }
  }

 
  //if first row and first column is zero
  if(firstrow==1)
   for(i=0;i<n;i++)
    a[0][i]=0;
 
  if(firstcol==1)
   for(i=0;i<n;i++)
    a[i][0]=0;  
 
 

 //print the matrix
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
     printf("%d ",a[i][j]);
    printf("\n");
  }      
 
getchar();
return 0;


   
}


