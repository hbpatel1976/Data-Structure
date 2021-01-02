#include <stdio.h> 
struct node 
{ 
	int data; 
	int color; 
	struct node* parent; 
	struct node* right; 
	struct node* left; 
}; 

struct node* root = NULL; 

struct node* bst(struct node* trav, struct node* temp) 
{ 
	if (trav == NULL) return temp; 
	if (temp->data < trav->data) 
	{ 
		trav->left = bst(trav->left, temp); 
		trav->left->parent = trav; 
	} 
	else if (temp->data > trav->data) 
	{ 
		trav->right = bst(trav->right, temp); 
		trav->right->parent = trav; 
	} 
	return trav; 
} 

void rightRotate(struct node* temp) 
{ 
	struct node* lft = temp->left; 
	temp->left = lft->right; 
	if (temp->left) temp->left->parent = temp; 
	lft->parent = temp->parent; 
	if (!temp->parent) root = lft; 
	else if (temp == temp->parent->left) temp->parent->left = lft; 
	else temp->parent->right = lft; 
	lft->right = temp; 
	temp->parent = lft; 
} 

void leftRotate(struct node* temp) 
{ 
	struct node* rgt = temp->right; 
	temp->right = rgt->left; 
	if (temp->right) temp->right->parent = temp; 
	rgt->parent = temp->parent; 
	if (!temp->parent) root = rgt; 
	else if (temp == temp->parent->left) temp->parent->left = rgt; 
	else temp->parent->right = rgt; 
	rgt->left = temp; 
	temp->parent = rgt; 
} 

void adjustNodes(struct node* root, struct node* pt) 
{ 
	struct node* parent_pt = NULL; 
	struct node* grand_parent_pt = NULL; 
	while ((pt != root) && (pt->color != 0) && (pt->parent->color == 1)) 
	{ 
		parent_pt = pt->parent; 
		grand_parent_pt = pt->parent->parent; 
		/* Case A: Parent of pt is left child of Grand-parent of pt */
		if (parent_pt == grand_parent_pt->left) 
		{ 
			struct node* uncle_pt = grand_parent_pt->right; 
			/* Case A(1): The uncle of pt is also red Only Recoloring required */
			if (uncle_pt != NULL && uncle_pt->color == 1) 
			{ 
				grand_parent_pt->color = 1; 
				parent_pt->color = 0; 
				uncle_pt->color = 0; 
				pt = grand_parent_pt; 
			} 
			else 
			{ 
			/* Case A(2): pt is right child of its parent Left-rotation required */
			if (pt == parent_pt->right) 
				{ 
					leftRotate(parent_pt); 
					pt = parent_pt; 
					parent_pt = pt->parent; 
				} 
			/* Case A(3): pt is left child of its parent Right-rotation required */
			rightRotate(grand_parent_pt); 
			int t = parent_pt->color; 
			parent_pt->color = grand_parent_pt->color; 
			grand_parent_pt->color = t; 
			pt = parent_pt; 
			} 
		} 

		/* Case B: Parent of pt is right child of Grand-parent of pt */
		else { 
			struct node* uncle_pt = grand_parent_pt->left; 

			/* Case B(1): The uncle of pt is also red Only Recoloring required */
			if ((uncle_pt != NULL) && (uncle_pt->color == 1)) 
			{ 
				grand_parent_pt->color = 1; 
				parent_pt->color = 0; 
				uncle_pt->color = 0; 
				pt = grand_parent_pt; 
			} 
			else { 
				/* Case B(2): pt is left child of its parent Right-rotation required */
				if (pt == parent_pt->left) { 
					rightRotate(parent_pt); 
					pt = parent_pt; 
					parent_pt = pt->parent; 
				} 

				/* Case B(3): pt is right child of its parent Left-rotation required */
				leftRotate(grand_parent_pt); 
				int t = parent_pt->color; 
				parent_pt->color = grand_parent_pt->color; 
				grand_parent_pt->color = t; 
				pt = parent_pt; 
			} 
		} 
	} 
	root->color = 0; 
} 

void inorder(struct node* trav) 
{ 
	if (trav == NULL) return; 
	inorder(trav->left); 
	printf("%d ", trav->data); 
	inorder(trav->right); 
} 

int main() 
{ 
	int i,n = 12; 
	int a[12] = {11,19,6,14,17,31,24,41,61,3,1,69}; 

	for (i = 0; i < n; i++) 
	{ 
	struct node* temp = (struct node*)malloc(sizeof(struct node)); 
	temp->right = NULL; 
	temp->left = NULL; 
	temp->parent = NULL; 
	temp->data = a[i]; 
	temp->color = 1; 

	root = bst(root, temp); 

	adjustNodes(root, temp); 
	} 

	printf("Inoder Traversal of Created Tree\n"); 
	inorder(root); 
	return 0; 
}
