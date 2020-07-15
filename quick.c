/* quick sort */
#include<stdio.h>
int main()
{
	int A[] = {34, 90, 21, 43, 87, 2, 67, 53, 9, 23, 82}, i;
	QuickSort (A, 0, 10);
	for(i=0; i<11; ++i) printf("%d ",A[i]);
	return 0;
}
int Partition (int *A, int start, int end)
{
	int i, k, temp;
	int pivot = A[end];
	int partitionIndex = start;
	for (i=start; i<end; ++i)
	{
		printf ("i=%d A[i]=%d Pivot=%d Partition Index=%d\n",i,A[i], pivot, partitionIndex);
		if(A[i]<pivot)
		{
			temp = A[i];
			A[i] = A[partitionIndex];
			A[partitionIndex] = temp;
			partitionIndex++;
		}
	for(k=start; k<=end; ++k)printf("*%d ",A[k]);printf("\n");
	}
	temp = A[end];
	A[end] = A[partitionIndex];
	A[partitionIndex] = temp;
	
	printf("Partition Index = %d\n",partitionIndex);
	for(k=start; k<=end; ++k)printf("#%d ",A[k]);printf("\n");
	return partitionIndex;
}
int QuickSort (int *A, int start, int end)
{
	int i;
	if(start < end)
	{
		int partitionIndex = Partition (A, start, end);
		QuickSort (A, start, partitionIndex-1);  
		QuickSort (A, partitionIndex+1, end);  
	}
	return 0;
}
