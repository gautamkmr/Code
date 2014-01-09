#include<stdio.h>
 void star(int i) {
if (i > 1) {
star(i/2);
star(i/2);
}
printf( "hello\n");   
  }


int main()
{
star(5);    
printf(".........\n");
char f[]="Gautam";
int i=(int)f;

printf("%p\n",i);
return 0;




}





