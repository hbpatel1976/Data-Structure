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
if((rear+1)%size==front)
  {
  printf("Overflow\n");
  }
else if(front==-1 && rear==-1)
  {
  front=rear=0;
  queue[rear]=element;
  }
else 
  {
  rear=(rear+1)%size;
  queue[rear]=element;
  }
}

void dequeue(void)
{
if(front==-1 && rear==-1)
  {
  printf("Underflow\n");
  }
else if(front==rear)
  {
  printf("Element deleted=%d\n",queue[front]); 
  front=rear=-1;
  }
else 
  {
  printf("Element deleted=%d\n",queue[front]); 
  front=(front+1)%size;
  }
}

void display(void)
{
int i=front;
if(front==-1 && rear==-1)
  printf("Queue Empty\n");
else 
  {
  while(i != rear)
        {
        printf("%d\t",queue[i]);
        i=(i+1)%size;
        }
  printf("\n");
  }
}

void peek (void)
{
	if(front==-1 && rear==-1)printf("Queue Empty\n");
	else printf("Data at front=%d\n",queue[front]);
}
