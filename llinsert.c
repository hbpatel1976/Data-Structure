#include <stdio.h>
struct node
	{
	int data;
	struct node *next;
	};
int totalNode=0;
struct node *start=NULL, *newnode, *temp;
int main ()
{
int choice, pos;
do
	{
	printf("\n1: Insert in beginning\n");
	printf("2: Insert at end\n");
	printf("3: Insert after a position\n");
	printf("4: Display\n");
	printf("5: Exit\n");
	printf("Enter your choice : ");
	scanf("%d", &choice);
	if(choice==1 || choice==2 || choice==3)
	{
		newnode = (struct node*) malloc (sizeof (struct node));
		printf("Enter data : ");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
	}
	switch(choice)
		{
		case 1:
			insertBegin();
			break;
		case 2:
			insertEnd();
			break;
		case 3:
			insertPos(pos);
			break;
		case 4:
			display();
			break;
		case 5:
			break;
		default:
			printf("Invalid Choice...Please try again...\n");
		}
	}while(choice != 5);
}

void insertBegin(void)
{
	newnode->next=start;
	start=newnode;
}

void insertEnd(void)
{
	temp = start;
	while (temp->next != NULL)
		{
		temp=temp->next;
		}
	temp->next = newnode;
}

void insertPos(int p)
{
	int count=1;
	temp=start;
	while (count < p)
		{
		temp=temp->next;
		count++;
		}
	newnode->next = temp->next;
	temp->next = newnode;
}

void display(void)
{
	temp=start;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
	}
}
