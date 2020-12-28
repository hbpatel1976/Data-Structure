#include <stdio.h> 
struct node 
{ 	int data; 
	struct node *left, *right; 
}; 

struct node* newnode(int item) 
{ 
	struct node* temp  = (struct node*)malloc(sizeof(struct node)); 
	temp->data = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

void inorder(struct node* root) 
{ 
	if (root != NULL) 
	{ 	inorder(root->left); 
		printf("%d  ", root->data); 
		inorder(root->right); 
	} 
} 

struct node* insert(struct node* node, int data) 
{ 
	if (node == NULL) return newnode(data); 
	if (data < node->data) node->left = insert(node->left, data); 
	else if (data > node->data) node->right = insert(node->right, data); 
	return node; 
} 

int main() 
{ 
	struct node* root = NULL; 
	root = insert(root, 12); 
	insert(root, 7); 
	insert(root, 9); 
	insert(root, 18); 
	insert(root, 14); 
	insert(root, 1); 
	insert(root, 45); 
	insert(root, 89); 
	insert(root, 100); 
	insert(root, 36); 
	insert(root, 59); 
	inorder(root); 
	return 0; 
}
