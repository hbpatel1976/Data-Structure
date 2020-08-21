#include <stdio.h>
void main()
	{
	int pow(int,int);
	int b=2,e=5,ans;
	ans=pow(b,e);
	printf("%d power %d = %d",b,e,ans);
	}
int pow(int b, int e)
	{
	if(e<=0)return 1;
	else return (b * power(b,e-1));
	}
