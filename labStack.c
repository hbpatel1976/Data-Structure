#include <stdio.h>
#define size 5
int top=-1;
int stack[size];
void main()
{
	push(100);
	push(200);
	push(300);
	push(400);
	push(500);
	push(600); /* Error Message : Stack Full */
	printf("Data popped = %d\n",pop()); /* 500 */
	printf("Data popped = %d\n",pop()); /* 400 */
	printf("Data popped = %d\n",pop()); /* 300 */
	printf("Data peeped = %d\n",peep()); /* 200 */
	printf("Data popped = %d\n",pop()); /* 200 */
	printf("Data popped = %d\n",pop()); /* 100 */
	printf("Data popped = %d\n",pop()); /* Error Message: Stack Empty */
}

void push(int data)
{
	if(!(isFull())) stack[++top]=data; /* if(isFull()==0) OR if(isFull()!=1)*/
	else printf("Stack is already full....no more data item can be pushed\n");
}

int pop ()
{
	if(!(isEmpty())) return stack[top--];
	else {printf("Stack is empty....no more data item can be popped\n");return -999;}
}

int peep()
{
if (top != -1)return stack[top];
else return -999;
}

isFull()
{
if(top==size-1)return 1;
else return 0;
}

int isEmpty()
{
if(top==-1)	return 1;
else return 0;
}
