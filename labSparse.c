#include <stdio.h>
#define row 4
#define col 6
void main()
{
int original[row][col]={0,0,0,0,2,0,1,0,0,0,0,0,0,0,0,4,0,0,0,3,0,0,0,0};
if(isSparse(original)==1)
	{
		printf("Sparse Matrix\n");
		Convert2Sparse(original);
	}
else printf("Not Sparse Matrix\n");
}

isSparse(int origin[row][col])
{
	int count=0, i, j;
	for(i=0; i<row; ++i)
	{
		for(j=0; j<col; ++j)
		{
			if(origin[i][j]==0)count++;
		}
	}
	if(count > (row*col)/2)return 1; /* Sparse */
	else -1; /* Not Sparse */
}

Convert2Sparse(int origin[row][col])
{
	int sparse[row*col][3], line=0, i, j;	
	for(i=0; i<row; ++i)
	{
		for(j=0; j<col; ++j)
		{
			if(origin[i][j]!=0)
			{
				sparse[line][0]=i;
				sparse[line][1]=j;
				sparse[line][2]=origin[i][j];
				line++;
			}
		}
	}
	/* Print the Sparse Matrix */
	printf("\n Resultant Sparse Matrix\n");
	for(i=0; i<line; ++i)
	{
		printf("%d\t%d\t%d\n",sparse[i][0], sparse[i][1], sparse[i][2]);
	}
}
