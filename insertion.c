/* insertion sort */
#include<stdio.h>
int main()
{
   int i, hole, count=10, value, number[25]={42, 23, 74, 11, 65, 58, 94, 36, 99, 87};

   for(i=1;i<count;i++){
      value=number[i];
      hole=i-1;
      while((value<number[hole])&&(hole>=0))
	  {
         number[hole+1]=number[hole];
         hole=hole-1;
      }
      number[hole+1]=value;
   }

   printf("Order of Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);

   return 0;
}
