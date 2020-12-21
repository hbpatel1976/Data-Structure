/* Adjacency List Representation of Graph */
#include <stdio.h>
#include <conio.h>
#define size 6
/* For the graph in the lecture note */
struct node
	{
	int node;
	struct node * next;
	};
void main()
{
int i,j;
int matrix[size][size]	={
			{0,1,1,0,0,0},
			{1,0,1,1,1,0},
			{1,1,0,0,1,0},
			{0,1,0,0,0,1},
			{0,1,1,0,0,1},
			{0,0,0,1,1,0}
			};
struct node *list[size],*newnode,*temp;
clrscr();
for(i=0; i<size; ++i)list[i]=NULL;
for(i=0; i<size; ++i)
	{
	for(j=0; j<size; ++j)
		{
		if(matrix[i][j]==1)
			{
			newnode = (struct node*) malloc (sizeof(struct node));
			newnode->node=j+1;
			newnode->next=NULL;
			if(list[i]==NULL)list[i]=newnode;
			else
				{
				temp=list[i];
				while(temp->next != NULL) temp=temp->next;
				temp->next=newnode;
				}
			}
		}
	printf("\n");
	}

for(i=0; i<size; ++i)
	{
	temp=list[i];
	printf("Neighbours of Node # %d : ",i+i);
	while(temp!=NULL)
		{
		printf("%d\t",temp->node);
		temp=temp->next;
		}
	printf("\n");
	}
getch();
}