#include<stdio.h>
    int atoi(const char *str) {
    int res = 0;
    int i=0;
    int flag=1;
    while(str[i]==' ')
     i++;
    if(str[i]=='+')
    {
        flag = 1;
        i++;
    }
    if(str[i]=='-')
    {
        flag = -1;
        i++;
    }
    for (; str[i] != '\0'; ++i)
    {
       if(str[i]>='0' && str[i]<='9') 
         res = res*10 + str[i] - '0';
       if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')||str[i]==' ')
      //{

       // printf("%c %d\n",str[i],i);
        break;
      // } 
    }
        

    return res*flag;
    }

int main()
{
  printf("%d\n",atoi("        +004500"));
  return 0;
}
