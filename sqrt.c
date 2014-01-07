#include<stdio.h>
//#include<stdlib.h>
double sqrt(double a)
{
  if(a<0)  return -1;  //imaginary numbers
  if(a==0 || a==1)  return a;

  double start,end,mid, precision;
  start = 0;
  end = a;
  precision = 0.00001;


  while((end - start) > precision)
  {
    mid = start + (end - start)/2;
    double midsqr = mid*mid;
    if(midsqr == a)  return mid;
    
    if(midsqr < a)  start = mid;
    else end = mid;
  }
  //if a was not nearly perfect square return the approx value
  return (start + end)/2;  
}
int main()
{

 printf("%f\n",sqrt(50)); 
 printf("%f\n",sqrt(20)); 
 printf("%f\n",sqrt(.34)); 
 printf("%f\n",sqrt(.99));
 printf("%f\n",sqrt(25)); 
  
 return 0;
}
