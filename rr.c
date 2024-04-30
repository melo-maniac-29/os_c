#include<stdio.h>
void swap(int *a,int *b){
 int t ;
 t= *a;
 *a= *b;
 *b= t;
}
void main(){
	int bt[10],p[10],x,ta,wt[10],n,ct[10],i,j,temp[10],time_quantum,total=0,count;
	float twt=0,tat=0,awt,att;
	printf("Enter the total number of process:");
	scanf("%d",&n);
	x=n;
	for(i =0;i<n;i++){
	printf("Enter the burst time of P%d ",i);
	scanf("%d",&bt[i]);
	p[i]=i;
	 temp[i] = bt[i];
	}
	printf("\nEnter Time Quantum:\t"); 
    scanf("%d", &time_quantum); 
    printf("\nProcess \tBT\t TAT\t WT\n");
    for(total = 0, i = 0; x != 0;) 
    { 
        if(temp[i] <= time_quantum && temp[i] > 0) 
        { 
         total = total + temp[i]; 
         temp[i] = 0; 
         count = 1; 
        } 
        else if(temp[i] > 0) 
        { 
         temp[i] = temp[i] - time_quantum; 
         total = total + time_quantum; 
        } 
        if(temp[i] == 0 && count == 1) 
        { 
         x--; 
         printf("\nP%d\t\t%d\t%d\t%d", i + 1, bt[i], total, 
         total - bt[i]);
         twt = twt + total - bt[i]; 
         tat = tat + total ; 
         count = 0; 
        } 
        if(i == n - 1) 
        {
         i = 0; 
        }
        else 
        {
         i++;
        }
    } 
    awt = twt * 1.0 / n;
    att = tat * 1.0 / n;
    printf("\n\nAverage Waiting Time:\t%f milliseconds", awt); 
    printf("\nAvg Turnaround Time:\t%f milliseconds \n",att ); 
}
