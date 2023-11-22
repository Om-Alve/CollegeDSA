#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};

struct node * top = NULL;

void push(){
	struct node *n = (struct node *)malloc(sizeof(struct node));
	printf("Enter the value: ");
	scanf("%d",&n->data);
	n->next = top;
	top = n;	
}

void pop(){
	if(top == NULL){
		printf("Stack underflow\n");
	}
	else{
		struct node *temp = top;
		printf("Element popped is %d\n",top->data);
		top = top->next;
		free(temp);
	}
	printf("\n");
}

void display(){
	struct node *temp = top;
	printf("Elements of Stack are: ");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void destroy(){
	struct node *n= top;
	while(n!=NULL){
		struct node * temp = n;
		n = n->next;
		free(temp);
	}
	printf("Stack Destroyed!\n");
}

int main(){
	int op;
	do{
		printf("MENU\n1.Push\n2.Pop\n3.Display\n4.Destroy\n5.Exit\n");
		scanf("%d",&op);
		switch(op){
			case 1:push(); break;
			case 2:pop(); break;
			case 3:display(); break;
			case 4:destroy(); break;
			case 5:break;
			default: printf("Invalid choice\n");
		}
	}while(op!=5);
	return 0;
}
