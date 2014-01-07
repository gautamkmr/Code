#include<stdio.h>
/*
Let the input string be “i like this program very much”. 
The function should change the string to “much very program this like i”
*/
/* UTILITY FUNCTIONS */
/*Function to reverse any sequence starting with pointer
  begin and ending with pointer end  */
void reverse(char *begin, char *end)
{
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}
/*
void reverseWords(char *s)
{
    char *word_begin = NULL;
    char *temp = s; 
 
    while( *temp )
    {
        if (( word_begin == NULL ) && (*temp != ' ') )
        {
            word_begin=temp;
        }
        if(word_begin && ((*(temp+1) == ' ') || (*(temp+1) == '\0')))
        {
            reverse(word_begin, temp);
            word_begin = NULL;
        }
        temp++;
    } 
 
    reverse(s, temp-1);
} 
*/
void reverseWords(char *s)
{
  char *wordbegin=NULL;
  char *tmp = s;
  while(*tmp)   //this will reverse each word in side the string
  {
    if((wordbegin==NULL) &&(*tmp!=' '))
     wordbegin = tmp;
    if(wordbegin && ((*(tmp+1)==' ') ||(*(tmp+1)=='\0')))
     {
        reverse(wordbegin,tmp);
        wordbegin =NULL;
     }
     tmp++;    
  }
  reverse(s,tmp-1);  //this will reverse entire string 
} 

/* Driver function to test above functions */
int main()
{
  char s[] = "i like this program very much";
  char *temp = s;
  reverseWords(s);
  printf("%s", s);
  getchar();
  return 0;
}
