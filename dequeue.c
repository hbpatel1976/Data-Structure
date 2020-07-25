/* Double ended queue - Dequeue */
#include <stdio.h>
#define size 5
int dequeue[size];
int front=-1, rear=-1;
int main()
{
	enqueueFront(11);
	enqueueRear(22);
	enqueueRear(33);
	display();
	dequeueFront();
	enqueueFront(44);
	enqueueFront(55);
	getFront();
	display();
	dequeueFront();
	dequeueRear();
	enqueueFront(66);
	dequeueRear();
	display();
	getRear();
	dequeueRear();
	dequeueFront();
	display();
	return 0;
}
void enqueueFront(int element)
{
	if((front==0 && rear==size-1) || (front==rear+1)) {printf("Queue is full\n");}
	else if(front==-1 && rear==-1) {front=rear=0; dequeue[front]=element;}
	else if(front==0) {front=size-1; dequeue[front]=element;}
	else {front--; dequeue[front]=element;}
}
void enqueueRear(int element)
{
	if((front==0 && rear==size-1) || (front==rear+1)) {printf("Queue is full\n");}
	else if(front==-1 && rear==-1) {front=rear=0; dequeue[rear]=element;}
	else if(rear==size-1) {rear=0; dequeue[rear]=element;}
	else {rear++; dequeue[rear]=element;}
}

void dequeueFront(void)
{
	if(front==-1 && rear==-1){printf("Queue is empty\n");}
	else if(front==rear) {printf("Element deleted = %d\n",dequeue[front]); front=rear=-1;}
	else if (front==size-1) {printf("Element deleted = %d\n",dequeue[front]); front=0;}
	else {printf("Element deleted = %d\n",dequeue[front]); front++;}
}

void dequeueRear(void)
{
	if(front==-1 && rear==-1){printf("Queue is empty\n");}
	else if(front==rear) {printf("Element deleted = %d\n",dequeue[rear]); front=rear=-1;}
	else if (rear==0) {printf("Element deleted = %d\n",dequeue[rear]); rear=size-1;}
	else {printf("Element deleted = %d\n",dequeue[rear]); rear--;}
}

void display(void)
{
	int i=front;
	printf("Dequeue -> \t");
	while (i != rear)
	{
		printf("%d\t",dequeue[i]);
		i=(i+1)%size;
	}
	printf("%d\n",dequeue[rear]);
}

void getFront (void)
{
	printf("Front Element = %d\n",dequeue[front]);
}

void getRear (void)
{
	printf("Rear Element = %d\n",dequeue[rear]);
}
