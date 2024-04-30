#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>


int main(){
	int pid;
	pid=fork();
	if(pid<0){
	printf("FORK FAILED \n");
	return 1;
	}
	else if(pid==0){
	printf("Child process successfully created\n");
	printf("Child_pid = %d ,Parent_pid =%d\n",getpid(),getppid());
	}
	else{
	wait(NULL);
	printf("Parent process successfully created\n");
	printf("Child_pid = %d ,Parent_pid =%d\n1",getpid(),getppid());
	}
	return 0;
}
