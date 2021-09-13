/* Swapping */
#include <stdio.h>
#define size 10
void main()
{
	int number[size] = {78,17,91,16,0,54,37,7,99,49},i,temp;
	printf("\nBefore swapping\n");
	for(i=0; i<size; ++i)printf("%d\t",number[i]);
	
	for(i=0; i<size; i+=2)
	{
		temp = number[i];
		number[i]=number[i+1];
		number[i+1]=temp;
	}
	printf("\nAfter swapping\n");
	for(i=0; i<size; ++i)printf("%d\t",number[i]);
}
