#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
void forkexample(){
	if(fork()==0){
	printf("Hello from Child\n");
	}
	else{
	printf("Hello from Parent\n");
	}
}
void main(){
	forkexample();
}
