#include <stdio.h>
void main()
{void fibo(int,int,int);
fibo(1,0,5); /* First term, second term, total terms */
}

void fibo(int t1, int t2, int totalterms)
{
printf("%d\t",t1+t2);
if(totalterms<=1) {return;}
else 	   {fibo(t2,t1+t2,totalterms-1);}
}
