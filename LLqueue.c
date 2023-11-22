#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};

struct node * front=NULL,*rear=NULL;

void insert(int x){
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->data=x;
	n->next=NULL;
	if(front == NULL && rear == NULL){
		front = rear = n;
	}
	else{
		rear->next = n;
		rear = n;
	}
}

void display(){
	if(front==NULL){
		printf("Queue Underflow");
	}
	else{
		printf("Elements of Queue are: ");
		struct node *n=front;
		while(n!=NULL){
			printf("%d ",n->data);
			n=n->next;
		}
		printf("\n");
	}
}

void deleteq(){
	if(front==NULL){
		printf("Queue Underflow");
	}
	else{
		struct node * temp = front;
		printf("Element deleted is %d\n",front->data);
		front = front->next;
		free(temp);
	}
}

void destroy(){
	struct node *n=front,*temp;
	while(n!=NULL){
		temp = n;
		n = n->next;
		free(temp);
	}
	printf("Queue Destroyed!\n");
}
