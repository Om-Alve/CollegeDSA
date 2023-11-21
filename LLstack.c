#include<stdio.h>
#include<conio.h>


struct node{
	int data;
	struct node *next;
};

struct node top,newrec,temp;

void push(){
	int x;
	printf("Enter the element to push:\n");
	scanf("%d",&x);
	newrec = (struct node *)malloc(sizeOf(struct *node))
	newrec->data = x;
	newrec->next = top;
	top = newrec;
}

void display(){
	if(top == NULL){
		printf("Stack underflow!");
		return;
	}
	temp = top;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

void destroy(){
	printf("The stack has been destroyed");
	top = NULL;
}

int main(){
	clrscr();
	int op;
	do{
		printf("MENU\n1.Push\n2.Pop\n3.Display\n4.Destroy\5.Exit\n");
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
	getch();
	return 0;
}
