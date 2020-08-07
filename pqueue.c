#include <stdio.h>
#define size 5
char PQElement[size*2];
int PQPriority[size*2];
int totalElement = 0;
int main()
{
	void PQInsert(char, int);
	void PQDelete(char, int);
	void display (void);
	PQInsert('A',2);
	PQInsert('B',4);
	PQInsert('C',1);
	PQInsert('D',5);
	PQInsert('E',3);
	PQInsert('F',3);
	display();
	PQDelete('C',1);
	display();
	return 0;
}
void PQInsert(char newElement, int newPriority)
{
	int count=0, k;
	while (count < totalElement)
		{
			if(newPriority>=PQPriority[count])count++;
			else break;
		}
	if(count!=totalElement)
		for(k=totalElement; k>count; --k)
			{
				PQElement[k]=PQElement[k-1];
				PQPriority[k]=PQPriority[k-1];
			}
	PQElement[count]=newElement;
	PQPriority[count]=newPriority;
	totalElement++;
}
void PQDelete(char deleteElement, int deletePriority)
{
	int count=0,i;
	while (count < totalElement)
		{
		if(PQElement[count]==deleteElement && PQPriority[count]==deletePriority)break;
		else count++;
		}
	if(count==totalElement)printf("The element to delete did not find in the list\n");
	else
		{
		for(i=count; i<totalElement; ++i)
			{
			PQElement[i]=PQElement[i+1];
			PQPriority[i]=PQPriority[i+1];
			}
		totalElement--;
		printf("Element %c deleted\n",deleteElement);
		}
}
void display(void)
{
	int i;
	for(i=0; i<totalElement; ++i)
	{
		printf("Element: %c Priority: %d\n",PQElement[i],PQPriority[i]);
	}
}
