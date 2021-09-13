/* Searching */
#include <stdio.h>
#define size 10
void main()
{
	int number[size] = {78,49,91,16,0,54,49,7,99,49};
	int search = 50, i, found=0;
	
	for(i=0; i<size; ++i) 
	{
		if(number[i]==search)
		{
			printf("Number %d found at location %d\n",search, i);
			found=1;
		}
	}
	if(found==0)printf("Number %d NOT FOUND\n",search);
}

