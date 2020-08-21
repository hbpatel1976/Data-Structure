#include <stdio.h>
void main()
	{
	int fact(int);
	int x=5,ans;
	ans=fact(x);
	printf("Factorial = %d",ans);
	}
int fact(int n)
	{
	if (n<=1) return 1;
	else return (n * fact(n-1));
	}
