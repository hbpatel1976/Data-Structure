/* selection sort */
#include<stdio.h>
int main()
{
   int i, j, iMin, temp, count=10, A[25]={42, 23, 74, 11, 65, 58, 94, 36, 99, 87};

   for(i=0;i<=count-2;i++)
	{
		iMin = i;
      for(j=i+1; j<=count-1; ++j)
      {
      	if(A[j]<A[iMin]) iMin = j;
	  }
      temp=A[i];
      A[i]=A[iMin];
      A[iMin]=temp;
   }

   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",A[i]);

   return 0;
}
