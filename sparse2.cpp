/* sparse matrix */
#include<stdio.h>
#define row 4
#define col 3
int main()
{
   int original[row][col]={0,5,0,0,0,8,0,0,0,1,0,0}, sparse[3][row];
   int i,j,count=0;
   for(i=0; i<row; ++i)
   {
   	for(j=0; j<col; ++j)
   	{
   	if(original[i][j]!=0) 
	   {
	   sparse[count][0]=i;
	   sparse[count][1]=j;
	   sparse[count][2]=original[i][j];
	   count++;
	   }
	}
   }
   for(i=0; i<count; ++i)
   {
   	printf("%d\t%d\t%d\n",sparse[i][0],sparse[i][1],sparse[i][2]);
   }
   return 0;
}
