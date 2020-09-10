#include <stdio.h>
struct node
	{
	int data;
	struct node *prev;
	};
struct node *top=NULL;
void main ()
{
	push(10);
	push(20);
	push(30);
	push(40);
	display();
	pop();
	display();
	peep();
	display();
}

void push(int item)
{
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data=item;
	newnode->prev=top;
	top=newnode;
}

void pop(void)
{
	struct node *temp=top;
	if(top==NULL){printf("Stack Empty"); return;}
	else {top=top->prev;free(temp);}
}
void display(void)
{
	struct node *temp=top;
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}
void peep(void)
{
	if(top==NULL){printf("Stack Empty"); return;}
	else {printf("Element on the top = %d\n",top->data);}
}
