/* binary search */
#include<stdio.h>
int main()
{
	int A[]={6,8,11,12,18,21,27,37,39,44,47,58,60,77}, n=14, x=39;
	int searchResult = searchBinary (A,n,x);
	if (searchResult == -1)printf("Element does not exist");
	else printf("Element %d found at poistion %d",x,searchResult);
	return 0;
}
int searchBinary (int A[], int n, int x)
{
	int i, start=0, end=n-1, middle;
	while (start <= end)
	{
		middle = (start + end)/2;
		printf("BEFORE: start=%d end=%d middle=%d x=%d\n",start, end, middle, x);
		if (A[middle]==x)return middle;
		else if (A[middle]>x) end=middle-1;
		else start=middle+1;
		printf("AFTER: start=%d end=%d middle=%d x=%d\n",start, end, middle, x);
	}
return -1;
}
