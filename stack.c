/* stack */
#include<stdio.h>
#define size 5
int S [size], top=-1;
int main()
{
	push(50);
	push(7);
	push(20);
	pop();
	push(14);
	pop();
	pop();
	printf("Stack top = %d",top);
	return 0;
}
void push(int x)
{
	if(top==size-1)
		{
			printf("Stack Overflow"); return;
		}
	else
		{
			top++;
			S[top]=x;
			printf("Element pushed : %d\n",S[top]);
		}
}
void pop(void)
{
if(top==-1)
		{
			printf("Stack Underflow"); return;
		}
	else
		{
			printf("Element popped : %d\n",S[top]);
			top--;
		}	
}
