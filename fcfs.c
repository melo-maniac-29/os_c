#include<stdio.h>
void main(){
	int p[5],bt,ta,wt[5],n,ct[5],tat[5];
	float twt=0,ttat=0;
	printf("Enter the total number of process:");
	scanf("%d",&n);
	for(int i =0;i<n;i++){
	printf("Enter the burst time of P%d ",i);
	scanf("%d",&p[i]);
	}
	bt=p[0];
	for(int i = 0;i<n;i++){
	ct[i]=bt;
	bt=bt+p[i+1];
	}
	for(int i = 0;i<n;i++){
	wt[i]=ct[i]-p[i];
	}

	for(int i=0;i<n;i++){
		tat[i]=ct[i]-p[i];
	}

	printf("\n");
	printf("Process\t\tBT\tCT\tTAT\tWT\n");
	for(int i = 0;i<n;i++){
	printf("P%d\t\t%d\t%d\t%d\t%d",i,p[i],ct[i],tat[i],wt[i]);
	printf("\n");
	}
	printf("\n");
	for(int i = 0;i<n;i++){
	twt=twt+wt[i];
	}
	for(int i = 0;i<n;i++){
	ttat=ttat+ct[i];
	}
	printf("Total Turn Around Time : %f\n",ttat);
	printf("Total waiting time : %f\n",twt);
	float avg = twt/n;
	float avgt = ttat/n;
	printf("Average Waiting Time = %f\n",avg);
	printf("Average Turn Around Time = %f\n",avgt);

}

