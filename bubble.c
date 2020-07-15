/* bubble sort */
#include<stdio.h>
int main()
{
int i, j, temp, count=6;
int A[25]={42, 23, 74, 11, 65, 58};

for(i=0;i<count-1;i++)
	{
	for(j=0; j<count-i-1; ++j)
	{
		if(A[j]>A[j+1]) 
      			{
			temp=A[j];
			A[j]=A[j+1];
			A[j+1]=temp;	
			}
		}
	}
printf("Order of Sorted elements: ");
for(i=0;i<count;i++) printf(" %d",A[i]);
return 0;
}

