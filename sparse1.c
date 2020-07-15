/* sparse matrix */
#include<stdio.h>
#define row 4
#define col 3
int main()
{
   int S[row][col]={0,5,0,0,0,8,0,0,0,1,0,0},status;
   status = isSparse(S);
   if(status==-1)printf("Not a sparse matrix");
   else printf("Sparse matrix: With %d zero elements from total %d elements", status, row*col);
   return 0;
}
int isSparse(int A[row][col])
{
	int i,j, count=0;
	for(i=0; i<row; ++i)
	{
		for(j=0; j<col; ++j)
		{
			if(A[i][j]==0)count++;
		}
	}
	if(count>=(row*col)/2)return count;
	else return -1;	
}
