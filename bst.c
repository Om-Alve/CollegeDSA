#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left,*right;
};

struct node * root = NULL;

void insert(int data){
	struct node *newnode = (struct node *)malloc(sizeof(struct node)),*current,*follow;
//	printf("Enter the value of the node: \n");
//  scanf("%d",&newnode->data);
	newnode->data = data;
	newnode->left = NULL;
	newnode->right=NULL;
	if(root == NULL){
		root = newnode;
		return;
	}
	else{
		current = root;
		follow = NULL;
		while(current!=NULL){
			follow = current;
			if(newnode->data < current->data){
				current = current->left;
			}
			else{
				current = current->right;	
			}
		}
		if(newnode->data < follow->data){
			follow->left = newnode;
		}
		else{
			follow->right = newnode;
		}
	}
}

void preorder(struct node *n){
	if(n==NULL){
		return;
	}
	printf("%d ",n->data);
	preorder(n->left);
	preorder(n->right);
}

void postorder(struct node *n){
	if(n==NULL){
		return;
	}
	postorder(n->left);
	postorder(n->right);
	printf("%d ",n->data);
}

void inorder(struct node *n){
	if(n==NULL){
		return;	
	}
	inorder(n->left);
	printf("%d ",n->data);
	inorder(n->right);
}

int main(){
	insert(3);
	insert(1);
	insert(4);
	insert(2);
	insert(5);
	printf("Pre-Order Traversal: ");
	preorder(root);
	printf("\n");
	printf("Post-Order Traversal: ");
	postorder(root);
	printf("\n");
	printf("In-order Traversal: ");
	inorder(root);
	printf("\n");
	return 0;
}
