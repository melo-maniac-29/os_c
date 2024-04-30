#include <stdio.h>
struct process 
{
	int ps;
	int flag;
} 
p[50];
struct sizes
{
	int size;
	int alloc;
} 
s[5];
	void firstFit(int np, int n) 
	{
		for (int i = 0; i < np; i++) 
		{
			for (int j = 0; j < n; j++) 
			{
				if (p[i].flag != 1) 
				{
					if (p[i].ps <= s[j].size && !s[j].alloc) 
					{
						s[j].alloc = 1;
						p[i].flag = 1;
						printf("Process %d allocated to block of size %d\n", i, s[j].size);
						break;
					}
				}

			}
			if (p[i].flag != 1) 
			{
				printf("Process %d must wait as there is no sufficient memory\n", i);
			}
		}
	}
	void bestFit(int np, int n) 
	{
		for (int i = 0; i < np; i++) 
		{
			int bestBlock = -1;
			for (int j = 0; j < n; j++) 
			{
				if (p[i].flag != 1)
	    		{
					if (p[i].ps <= s[j].size && !s[j].alloc) 
					{
						if (bestBlock == -1 || s[j].size < s[bestBlock].size)
						{
							bestBlock = j;
						}
					}
				}
			}
			if (bestBlock != -1) 
			{
				p[i].flag = 1;
				s[bestBlock].alloc = 1;
				printf("Process %d allocated to block of size %d\n",i, s[bestBlock].size);
			} 
			else 
			{
				printf("Process %d must wait as there is no sufficient memory\n", i);
			}
		}
	}
	void worstFit(int np, int n) 
	{
		for (int i = 0; i < np; i++) 
		{
int worstBlock = -1;
for (int j = 0; j < n; j++) {
if (p[i].flag != 1) {
if (p[i].ps <= s[j].size && !s[j].alloc) {
if (worstBlock == -1 || s[j].size >
s[worstBlock].size) {
worstBlock = j;
}
}
}
}
if (worstBlock != -1) {
p[i].flag = 1;
s[worstBlock].alloc = 1;
printf("Process %d allocated to block of size %d\n",
i, s[worstBlock].size);
} else {

printf("Process %d must wait as there is no sufficient memory\n", i);
}
}
}
int main() {
int np, n, choice;
printf("Memory Allocation Menu:\n");
printf("1. First Fit\n");
printf("2. Best Fit\n");
printf("3. Worst Fit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
printf("Enter the number of blocks: ");
scanf("%d", &n);
printf("Enter the size for %d blocks:\n", n);
for (int i = 0; i < n; i++) {
printf("Enter the size for block %d: ", i);
scanf("%d", &s[i].size);
s[i].alloc = 0;
}
printf("Enter the number of processes: ");

scanf("%d", &np);
printf("Enter the size of %d processes:\n", np);
for (int i = 0; i < np; i++) {
printf("Enter the size of process %d: ", i);
scanf("%d", &p[i].ps);
p[i].flag = 0;
}
switch (choice) {
case 1:
firstFit(np, n);
break;
case 2:
bestFit(np, n);
break;
case 3:
worstFit(np, n);
break;
default:
printf("Invalid choice. Please select 1, 2, or 3.\n");
}
return 0;

}
