#include <stdio.h>
struct node
	{
	int data;
	struct node *next;
	};
struct node *start=NULL, *newnode, *temp, *nextnode;
int main ()
{
	insertEnd(10);
	insertEnd(20);
	insertEnd(30);
	insertEnd(40);
	insertEnd(50);
	display();
	deleteBeginning();
	display();
	deleteEnd();
	display();
	deletePosition(2);
	display();
}

void insertEnd(int element)
{
	newnode = (struct node *) malloc (sizeof(struct node));
	newnode -> data = element;
	newnode -> next = NULL;
	if(start==NULL)
		{
		start=newnode;	
		}
	else
		{
		temp = start;
		while (temp->next != NULL)
			{
			temp=temp->next;
			}
		temp->next = newnode;
		}
}

void display(void)
{
	temp=start;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void deleteBeginning ()
{
	if(start == NULL)
	{
		printf("No Element in the List\n");
	}
	else
	{
		temp = start;
		start = start -> next;
		free (temp);
	}
}

void deleteEnd ()
{
	temp = start;
	if (temp->next == NULL)
	{
		start = NULL;
		free (temp);
	}
	else
	{
		while (temp -> next -> next != NULL)
		{
			temp = temp -> next;
		}
		free (temp->next);
		temp->next=NULL;
	}
}

void deletePosition (int p)
{
	temp = start;
	int i;
	for(i=1; i<p-1; ++i)
	{
		temp = temp -> next;
	}
	nextnode = temp -> next;
	temp -> next = nextnode -> next;
	free (nextnode);
}
