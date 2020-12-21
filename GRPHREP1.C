/* Adjacency Matrix Representation of Graph */
#include <stdio.h>
#define size 6
/* For the graph in the lecture note */
void main()
{
int i,j;
int matrix[size][size]	={
			{0,1,1,0,0,0},
			{1,0,1,1,1,0},
			{1,1,0,0,1,0},
			{0,1,0,0,0,1},
			{0,1,1,0,0,1},
			{0,0,0,1,1,0}
			};
printf("ADJACENCY MATRIX REPRESENTATION OF A GRAPH\n");
for(i=0; i<size; ++i)
	{
	printf("Neighbours of Node # %d : ",i+1);
	for(j=0; j<size; ++j)
		{
		if(matrix[i][j]==1)printf("%d ",j+1);
		}
	printf("\n");
	}
}
