#include <stdio.h>
struct node
	{
	int data;
	struct node *next, *prev;
	};
struct node *start=NULL, *temp;
void main ()
{
	createDoublyLinkedList();
	display();
}

void createDoublyLinkedList(void)
{
	struct node * newnode;
	int choice=1;
	while (choice != 0)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter data to insert : ");
		scanf("%d",&newnode->data);
		newnode->next=newnode->prev=NULL;
		if (start==NULL)start=temp=newnode;
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}
		printf("Continue? 1: Yes, 0: No => ");
		scanf("%d",&choice);
	}
}
void display(void)
{
	temp=start;
	do
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}while(temp != start);
	printf("\n");
}
