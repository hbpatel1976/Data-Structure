#include<stdio.h> 
struct node 
{ 
	int data; 
	struct node *left; 
	struct node *right; 
	int height; 
}; 


int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 

int height(struct node *N) 
{ 
	if (N == NULL)return 0; 
	return N->height; 
} 

struct node* newnode(int data) 
{ 
	struct node* node = (struct node*) malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1;
	return(node); 
} 

struct node *rightRotate(struct node *t1) 
{ 
	struct node *t2 = t1->left; 
	struct node *t3 = t2->right; 

	t2->right = t1; 
	t1->left = t3; 

	t1->height = max(height(t1->left), height(t1->right))+1; 
	t2->height = max(height(t2->left), height(t2->right))+1; 

	return t2; 
} 

struct node *leftRotate(struct node *t1) 
{ 
	struct node *t2 = t1->right; 
	struct node *t3 = t2->left; 

	t2->left = t1; 
	t1->right = t3; 

	t1->height = max(height(t1->left), height(t1->right))+1; 
	t2->height = max(height(t2->left), height(t2->right))+1; 

	return t2; 
} 

int getBalance(struct node *N) 
{ 
	if (N == NULL) return 0; 
	return height(N->left) - height(N->right); 
} 

struct node* insert(struct node* node, int data) 
{ 
	if (node == NULL) 
		return(newnode(data)); 

	if (data < node->data) 
		node->left = insert(node->left, data); 
	else if (data > node->data) 
		node->right = insert(node->right, data); 
	else 
		return node; 

	node->height = 1 + max(height(node->left), 
						height(node->right)); 

	int balance = getBalance(node); 

	/* Left Left Case */
	if (balance > 1 && data < node->left->data) return rightRotate(node); 
	/* Right Right Case */
	if (balance < -1 && data > node->right->data) return leftRotate(node); 
	/* Left Right Case */
	if (balance > 1 && data > node->left->data) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 
	/* Right Left Case */
	if (balance < -1 && data < node->right->data) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 
	return node; 
} 

void preOrder(struct node *root) 
{ 
	if(root != NULL) 
	{ 
		printf("%d ", root->data); 
		preOrder(root->left); 
		preOrder(root->right); 
	} 
} 
void inOrder(struct node *root) 
{ 
	if(root != NULL) 
	{ 
		inOrder(root->left); 
		printf("%d ", root->data); 
		inOrder(root->right); 
	} 
}
void postOrder(struct node *root) 
{ 
	if(root != NULL) 
	{ 
		postOrder(root->left); 
		postOrder(root->right); 
		printf("%d ", root->data); 
	} 
}

int main() 
{ 
struct node *root = NULL; 

/* Constructing tree given in the above figure */
root = insert(root, 13); 
root = insert(root, 16); 
root = insert(root, 10); 
root = insert(root, 8); 
root = insert(root, 54); 
root = insert(root, 3); 
root = insert(root, 12);
root = insert(root, 11);
root = insert(root, 9);
root = insert(root, 59);
root = insert(root, 20);
root = insert(root, 15);
root = insert(root, 21);
printf("\nPreorder traversal of the constructed AVL tree is\n"); 
preOrder(root); 
printf("\nInorder traversal of the constructed AVL tree is\n"); 
inOrder(root); 
printf("\nPostorder traversal of the constructed AVL tree is\n"); 
postOrder(root); 

return 0; 
} 
