/***

Name: Abhinav Agarwal
Dept: CSE 2nd Year
Roll: 01

Write a menu driven program in C which will perform the following operations on Singly Linked List
         i)create a linked list
         ii)delete an element at the front
         iii)delete an element at the end
         iv)search for the key element
         v)delete an element after the key element
         vi)delete an element before the key element
         vii)display the contents of the list

***/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *head= NULL;
void insertend() {
	int d;
	struct node *x;
	printf("Enter data\n");
	scanf("%d",&d);
	struct node *temp= (struct node*)malloc(sizeof(struct node));
	(*temp).data=d;
	(*temp).link=NULL;
	if (head== NULL)
		head=temp;
	else {
		x=head;
		while (x->link!=NULL && x!=NULL)
		x= x->link;
		x->link=temp;
	}
}

void deletefront(struct node* temp ) {
	if(head==NULL)
	printf("List is empty\n");
	else {
	head = head->link;
	printf("Element Deleted from front\n");
	free(temp);
	}
}

void deleteend(struct node *temp) {
	struct node *prev;
	if(head==NULL)
		printf("List is empty\n");
	else if(head->link==NULL) {
	head=NULL;
	printf("Element deleted from end\n");
	}
	else {
		while(temp->link!=NULL) {
			prev=temp;
			temp=temp->link;
		}
	prev->link =NULL;
	printf("Element deleted from end\n");
	}
	free(temp);
}

int search(int find,struct node *temp) {
	int c=0;
	while(temp!=NULL) {
		c++;
		if (temp->data==find) {
			printf("Key Element found at node %d\n",c);
			break;
		}
		temp=temp->link;
	}
	if(temp==NULL)
        	printf("Key Element not found\n");
}

void deleteafter(int key,struct node* temp) {
	struct node *del;
	if (head==NULL)
		printf("List is empty\n");
	else {
        	while(temp!=NULL) {
			if(temp->data==key && temp->link==NULL) {
				printf("No element present after key element\n");break;}
			else if(temp->data==key) {
				del=temp->link;
				temp->link=del->link;
				free(del);
				printf("Element Deleted after key element\n");
				break;
			}
			temp=temp->link;
		}
		if (temp==NULL)
			printf("Key element not found\n");
	}
}

void deletebefore(int key,struct node* temp) {
	struct node *del=head,*before_del=head;int c=0;
	if (head==NULL)
		printf("List is empty\n");
	else {
		while(temp!=NULL) {
			c++;
			if ( c==1 && temp->data==key) {
				printf("No element present before the key element\n");
				break;
			}
			else if (temp->data==key && c==2) {
				head=head->link;
				printf("Element Deleted before key element\n");
				free(del);
				break;
			}
			else if (temp->data==key) {
				before_del->link=temp;
				free(del);
				printf("Element Deleted before key element\n");
				break;
			}
			before_del=del;
			del=temp;
			temp=temp->link;
		}
		if (temp==NULL)
			printf("Key element not found\n");
	}
}

void printlist(struct node* temp) {
	if(head==NULL)
		printf("List is empty\n");
	else {
		while(temp!=NULL) {
			printf("%d  ",(*temp).data);
			temp=(*temp).link;
		}
		printf("\n");
	}
}

 void main()
{
    int ch,s;
    printf("Enter 1 to insert element\nEnter 2 to delete element from front\nEnter 3 to delete element from end\nEnter 4 to search for the key element\nEnter 5 to delete element after the key element\nEnter 6 to delete element before the key element\nEnter 7 to print the list\nEnter 0 to exit\n");
    do {
	printf("Enter your choice: ");
	scanf("%d",&ch);
	switch (ch) {
		case 0:printf("Thank You!");
			exit(0);
		case 1:insertend();
			break;
		case 2:deletefront(head);
			break;
		case 3:deleteend(head);
			break;
		case 4:printf("Enter the search element\n");
			scanf("%d",&s);
			search(s,head);break;
		case 5:printf("Enter the key element\n");
			scanf("%d",&s);
			deleteafter(s,head);
			break;
		case 6:printf("Enter the key element\n");
			scanf("%d",&s);
			deletebefore(s,head);
			break;
		case 7:printlist(head);
			break;
		default:printf("Wrong choice\n");
		}
	}
    while(ch!=0);
}
