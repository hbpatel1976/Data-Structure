#include <stdio.h>
struct node
	{
	int data;
	struct node *next, *prev;
	};
struct node *start=NULL, *end=NULL, *temp;
void main ()
{
	createDoublyCircularLinkedList();
	displayForward();
	displayBackward();
}

void createDoublyCircularLinkedList(void)
{
	struct node * newnode;
	int choice=1;
	while (choice != 0)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter data to insert : ");
		scanf("%d",&newnode->data);
		newnode->next=newnode->prev=NULL;
		if (start==NULL)
			{
				start=end=newnode;
				start->next=start;
				start->prev=start;
			}
		else
			{
				end->next=newnode;
				newnode->prev=end;
				newnode->next=start;
				start->prev=newnode;
				end=newnode;
			}
		printf("Continue? 1: Yes, 0: No => ");
		scanf("%d",&choice);
	}
}
void displayForward(void)
{
	temp=start;
	do
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}while(temp != start);
	printf("\n");
}

void displayBackward(void)
{
	temp=end;
	do
	{
		printf("%d\t",temp->data);
		temp=temp->prev;
	}while(temp != end);
	printf("\n");
}
