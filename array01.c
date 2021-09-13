/* Static Memory Allocation */
/* Count total number of pass/fail students along with their percentage */
#include <stdio.h>
#define size 10
void main()
{
	int marks[size] = {78,45,91,16,0,54,49,7,99,11};
	int i, countPass=0, countFail=0;
	for(i=0; i<size; ++i)
	{
		if(marks[i]>=35) {countPass++;}
		else {countFail++;}
	}
	printf("Pass students = %d\n", countPass);
	printf("Fail students = %d\n", countFail);
	printf("Percentage of Pass Students = %f\n",(countPass/(size*1.0))*100.0);
	printf("Percentage of Fail Students = %f\n",((countFail*1.0)/size)*100.0);
}
