/* Replace */
#include <stdio.h>
#define size 10
void main()
{
	int number[size] = {78,49,91,16,0,54,49,7,99,49};
	int find = 49, replace = -999, i, found=0;
	
	for(i=0; i<size; ++i) 
	{
		if(number[i]==find)
		{
			number[i]=replace;
			found=1;
		}
	}
	if(found==0)printf("Number %d NOT FOUND\n",find);
	else
		{
			printf("Updated Numbers\n");
			for(i=0; i<size; ++i)
				{
				printf("%d\n",number[i]);
			}
		}
}
