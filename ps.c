#include<stdio.h>
void swap(int *a,int *b){
 int t ;
 t= *a;
 *a= *b;
 *b= t;
}
void main(){
	int bt[10],p[10],x,ta[10],wt[10],n,ct[10],i,j,pr[10];
	float tat=0,twt=0;
	printf("Enter the total number of process:");
	scanf("%d",&n);
	for(i =0;i<n;i++){
	printf("Enter the burst time and prioritiy of P%d",i);
	scanf("%d %d",&bt[i],&pr[i]);
	p[i]=i;
	}
	for(i = 0;i<n;i++){
		for(j=i+1;j<n; j++){
			if(pr[i]>pr[j]){
				swap(&pr[i],&pr[j]);
				swap(&bt[i],&bt[j]);
				swap(&p[i],&p[j]);
		        }
		}
	}
	x=bt[0];
	for(i = 0;i<n;i++){
	ct[i]=x;
	x=x+bt[i+1];
	}
	for(i = 0;i<n;i++){
	wt[i]=ct[i]-bt[i];
	}

		for(int i=0;i<n;i++){
		ta[i]=ct[i]-bt[i];
	}
	printf("\n");
	printf("Process\t\tBT\tPRI\tCT\tTAT\tWT\n");
	for(int i = 0;i<n;i++){
	printf("P%d\t\t%d\t%d\t%d\t%d\t%d",p[i],bt[i],pr[i],ct[i],ta[i],wt[i]);
	printf("\n");
	}
	printf("\n");
	for(i = 0;i<n;i++){
	twt=twt+wt[i];
	}
	for(int i = 0;i<n;i++){
	tat=tat+ct[i];
	}
	printf("Total Turn Around Time : %f\n",tat);
	printf("Total waiting time : %f\n",twt);
	float avg = twt/n;
	float avgt = tat/n;
	printf("Average Waiting Time = %f\n",avg);
	printf("Average Turn Around Time = %f\n",avgt);
}
