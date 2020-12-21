/* Breadth First Search Traversal Algorithm for Graph */
#include <stdio.h>
#define size 8
int output[size], outputPtr=0, queue[size], front=-1, rear=-1;
void main()
{	
int matrix[size][size]=
		{
		{0,1,1,0,0,0,1,0},
		{1,0,1,1,1,0,0,0},
		{1,1,0,0,1,0,0,0},
		{0,1,0,0,0,1,0,1},
		{0,1,1,0,0,1,1,0},
		{0,0,0,1,1,0,0,0},
		{1,0,0,0,1,0,0,1},
		{0,0,0,1,0,0,1,0}
		};

int i, j, k, start=5,temp,isthere;
void enqueue(int);

enqueue(start);
while(!(front==-1 && rear==-1))
	{
	temp=dequeue();
	printf("%d\t",temp);
	output[outputPtr++]=temp;
	if(outputPtr>=size)break;
	for(j=0; j<size; ++j)
		{
		if(matrix[temp-1][j]==1)
			{
			isthere=0;
			for(k=0; k<outputPtr; ++k)
				{
				if(output[k]==j+1)isthere=1;
				}
			if(!(front==-1 && rear==-1))
			for(k=front; k<=rear; ++k)
				{
				if(queue[k]==j+1)isthere=1;
				}
			if(isthere==0)enqueue(j+1);
			}
		}
	}
}

void enqueue(int node)
	{
	if(front==-1 && rear==-1)front=rear=0;
	else rear++;
	queue[rear]=node;
	}

int dequeue(void)
	{
	int temp=queue[front];
	if(front==0 && rear==0){front=rear=-1;}
	else front++;
	return temp;
	}
