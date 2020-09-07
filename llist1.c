#include <stdio.h>
struct node
	{
	int data;
	struct node *next;
	};
int main ()
{
struct node *start=NULL, *newnode, *temp;
int choice;
do
	{
	newnode = (struct node*)malloc (sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(start==NULL) {start = temp = newnode;}
	else
		{
		temp->next = newnode;
		temp=newnode;
		}
	printf("Do you wish to continue? (1 For Yes / 0 For No) : ");
	scanf("%d",&choice);
	}while(choice != 0);

temp = start;
while (temp != NULL)
	{
	printf("%d\t",temp->data);
	temp=temp->next;
	}
}

