#include <stdio.h>
#define m 10
#define size 20
struct hashing
{
	int data;
	struct hashing *next;
};
void main()
{
	struct hashing *hash[m], *newnode, *temp;
	int list[size]={23,54,10,55,67,32,44,77,2,9,53,94,30,15,167,352,434,767,27,98}, i, pos;
	
	for(i=0; i<m; ++i) hash[i]=NULL;
	
	for (i=0; i<size; ++i)
	{
		pos = (2 * list[i] + 3) % m;
		if(hash[pos]==NULL)
		{
			newnode =  (struct hashing *) malloc (sizeof(newnode));
			newnode->data = list[i];
			newnode->next = NULL;
			hash[pos]=newnode;
		}
		else
		{
			temp=hash[pos];
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			newnode =  (struct hashing *) malloc (sizeof(newnode));
			newnode->data = list[i];
			newnode->next = NULL;
			temp->next=newnode;
		}		
	}
	for(i=0; i<m; ++i)
	{
		temp=hash[i];
		printf("Hash Index : %d ->", i);
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
