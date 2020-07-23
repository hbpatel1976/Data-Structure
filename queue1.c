#include <stdio.h>
#define size 5
int queue[size];
int front=-1, rear=-1;
int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(-5);
	display();
	peek();
	dequeue();
	peek();
	display();
	return 0;
}
void enqueue(int element)
{
	if(rear==size-1){printf("Overflow\n");}
	else if(front==-1 && rear==-1){front=rear=0;queue[rear]=element;}
	else {rear++;queue[rear]=element;}
}
void dequeue(void)
{
	if(front==-1 && rear==-1){printf("Underflow\n");}
	else if(front==rear){printf("Element deleted=%d\n",queue[front]); front=rear=-1;}
	else {printf("Element deleted=%d\n",queue[front]); front++;}
}
void display(void)
{
	int i;
	if(front==-1 && rear==-1)printf("Queue Empty\n");
	else {for(i=front; i<=rear; ++i)printf("%d\t",queue[i]);printf("\n");}
}
void peek (void)
{
	if(front==-1 && rear==-1)printf("Queue Empty\n");
	else printf("Data at front=%d\n",queue[front]);
}
