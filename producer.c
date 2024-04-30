#include<stdio.h>
#include<stdlib.h>


int mutex =1,full=0,empty =3;

int signal(int s){
s++;
return s; 
}


int wait(int s){
s--;
return s; 
}

void producer(){
	mutex= wait(mutex);
	full = signal(full);
	empty = wait(empty);
	printf("Buffer contains %d items\n",full);
	mutex = signal(mutex);
}

void consumer(){
	mutex= wait(mutex);
	empty = signal(empty);
	full = wait(full);
	printf("Buffer contains %d items\n",full);
	mutex = signal(mutex);
}

void main(){
	int n;
	while(1){
	
		printf("Choose 1.PROUCER 2.CONSUMER 3.EXIT\n");
		printf("Enter your choice: ");
		scanf("%d",&n);
		switch(n){
		case 1: if(mutex==1&&empty!=0){producer();}
				else {printf("BUFFER IS FULL\n");}
				break;
		case 2 : if(mutex==1&&full!=0){consumer();}
				else {printf("BUFFER IS EMPTY\n");}
				break;
		case 3: exit(0);
		}
	}
}
