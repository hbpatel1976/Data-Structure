#include <stdio.h>
struct node
	{
	int data;
	struct node *next;
	};
struct node *start=NULL, *temp;
void main ()
{
	void createCircularLinkedList(void);
	void display(void);
	createCircularLinkedList();
	display();
}

void createCircularLinkedList(void)
{
	struct node * newnode;
	int choice=1;
	while (choice != 0)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("Enter data to insert : ");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if (start==NULL)start=temp=newnode;
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
		temp->next=start;
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
