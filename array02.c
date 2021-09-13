/* Static Memory Allocation */
/* Allocating Grades to Students along with their percentage */
#include <stdio.h>
#define size 10
void main()
{
	int marks[size] = {78,45,91,16,0,54,49,7,99,11};
	int i, distinction=0, firstClass=0, secondClass=0, passClass=0, fail=0, invalidMarks=0;
	for(i=0; i<size; ++i)
	{
		if(marks[i]>=81 && marks[i]<=100) {distinction ++;}
		else if(marks[i]>=61 && marks[i]<=80) {firstClass ++;}
		else if(marks[i]>=50 && marks[i]<=60) {secondClass ++;}
		else if(marks[i]>=35 && marks[i]<=49) {passClass ++;}
		else if(marks[i]>=0 && marks[i]<=34) {fail ++;}
		else invalidMarks ++;
	}
	printf("Number of distinction students = %d\n", distinction);
	printf("Number of first class students = %d\n", firstClass);
	printf("Number of second class students = %d\n", secondClass);
	printf("Number of pass class students = %d\n", passClass);
	printf("Number of fail students = %d\n", fail);
	printf("Number of invalid entries = %d\n", invalidMarks);
	
	printf("Percentage of distinction students = %f\n", (distinction/(size*1.0))*100);
	printf("Percentage of first class students = %f\n", (firstClass/(size*1.0))*100);
	printf("Percentage of second class students = %f\n", (secondClass/(size*1.0))*100);
	printf("Percentage of pass class students = %f\n", (passClass/(size*1.0))*100);
	printf("Percentage of fail students = %f\n", (fail/(size*1.0))*100);
	printf("Percentage of invalid entries = %f\n", (invalidMarks/(size*1.0))*100);
}

