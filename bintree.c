#include <stdio.h>
struct node
{
	int data;
	struct node *right, *left;	
};
void main()
{
	struct node *createBinTree(void);
	struct node *root=NULL;
	root=createBinTree();
}
struct node *createBinTree(void)
{
	int d;
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter data : (-1 to exit) : ");
	scanf("%d",&d);
	if(d==-1)return NULL;
	newnode->data=d;
	newnode->right=NULL;
	newnode->left=NULL;
	printf("Enter left node of %d :\n",d);
	newnode->left = createBinTree();
	printf("Enter right node of %d :\n",d);
	newnode->right = createBinTree();
	return newnode;	
}
