#include <stdio.h>
struct node
	{
	int data;
	struct node *next;
	};
struct node *front=NULL, *rear=NULL;
void main ()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	display();
	dequeue();
	display();
	peep();
	display();
}

void enqueue(int item)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data=item;
	newnode->next=NULL;
	if(front==NULL && rear==NULL)front=rear=newnode;
	else {rear->next=newnode; rear=newnode;}
}

void dequeue(void)
{
	struct node *temp=front;
	if(front==NULL){printf("Queue Empty"); return;}
	else {front=front->next;free(temp);}
}
void display(void)
{
	struct node *temp=front;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void peep(void)
{
	if(front==NULL){printf("Queue Empty"); return;}
	else 
	{
		printf("Element at the front = %d\n",front->data);
		printf("Element at the end = %d\n",rear->data);
	}
}
