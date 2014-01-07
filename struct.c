#include<stdio.h>
#include<stdlib.h>
struct A{
int *a;
};


struct B{
int *b;
int c;
struct A *aa;
};

int main()
{
 int d;
 struct B *BB = (struct B *) malloc(sizeof(struct B));
 BB->c =9;
// BB->aa->a = &d;
 printf("Hello\n");
 return 0;
}

