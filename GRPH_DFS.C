/* Depth First Search Traversal Algorithm for Graph */
#include <stdio.h>
#define size 8

int output[size], outputPtr=0, stack[size], top=-1;
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
int i, j, k, start=1,temp,isthere,alreadyAnElementPushed;
void push(int);
push(start);
while(top!=-1)
	{
	temp=pop();
	printf("%d\t",temp);
	output[outputPtr++]=temp;
	if(outputPtr>=size)break;
	for(j=0; j<size; ++j)
		{
		alreadyAnElementPushed=0;
		if(matrix[temp-1][j]==1)
			{
			isthere=0;
			for(k=0; k<outputPtr; ++k)
				{
				if(output[k]==j+1)isthere=1;
				}
			if(top!=-1)
			for(k=0; k<=top; ++k)
				{
				if(stack[k]==j+1)isthere=1;
				}
			if(isthere==0)
				{
				push(j+1);
				alreadyAnElementPushed=1;
				}
			}
		if(alreadyAnElementPushed==1)break;
		}
	}
}

void push(int node)
	{
	stack[++top]=node;
	}

int pop(void)
	{
	return stack[top--];
	}