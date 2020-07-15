/* linear search */
#include<stdio.h>
int main()
{
	int A[]={77,12,8,39,27,21,44,18,6,47,11,37,60,56}, n=14, x=39;
	int searchLinear (int[],int,int);
	int searchResult = searchLinear (A,n,x);
	if (searchResult == -1)printf("Element does not exist");
	else printf("Element %d found at poistion %d",x,searchResult);
	return 0;
}
int searchLinear (int A[], int n, int x)
{
	int i;
	for(i=0; i<n; ++i)
	{
		if (A[i]==x)return i;
	}
return -1;
}
