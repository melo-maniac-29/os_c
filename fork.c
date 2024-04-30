#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int main()
{
 fork();
 fork();
 printf("hello\n");
 return 0;

}
