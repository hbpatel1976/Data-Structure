#include <stdio.h>
struct node
{
	int data;
	struct node *right, *left;	
};
void main()
{
	struct node *createBinTree(void);
	void preOrderTraversal (struct node *ptr);
	void postOrderTraversal (struct node *ptr);
	void inOrderTraversal (struct node *ptr);
	struct node *root=NULL;
	root=createBinTree();
	printf("\n Pre Order Tranversal : ");preOrderTraversal(root);
	printf("\n Post Order Tranversal : ");postOrderTraversal(root);
	printf("\n In Order Tranversal : ");inOrderTraversal(root);
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
void preOrderTraversal (struct node *ptr)
{
	if(ptr==NULL)return;
	printf("%d ",ptr->data);
	preOrderTraversal(ptr->left);
	preOrderTraversal(ptr->right);
}
void postOrderTraversal (struct node *ptr)
{
	if(ptr==NULL)return;
	postOrderTraversal(ptr->left);
	postOrderTraversal(ptr->right);
	printf("%d ",ptr->data);
}
void inOrderTraversal (struct node *ptr)
{
	if(ptr==NULL)return;
	inOrderTraversal(ptr->left);
	printf("%d ",ptr->data);
	inOrderTraversal(ptr->right);
}
