/***

Name: Abhinav Agarwal
Dept: CSE 2nd Year
Roll: 01
Write a menu driven program in C which will perform the following operations on Linked List
i)add a node at the end of the list
ii)no. of nodes present in the list
iii)add a new node at the beginning of the list
iv)add a new node after the specified no. of nodes
v)display the contents of the list

***/

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *link;
	}nd; 
	
nd *start;

void insertlast() {
	nd *temp,*ptr;
	temp=(nd*)malloc(sizeof(nd));
	printf("Enter the data : ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(start==NULL)
		start=temp;
	else {
		ptr=start;
		while(ptr->link!=NULL)
		ptr=ptr->link;
		ptr->link=temp;
		  }
	printf("Data Successfully Inserted\n");
}

void countnode() {
	nd *temp;
	temp=(nd*)malloc(sizeof(nd));
	temp=start;
	int count=0;
	while(temp!=NULL) {
		temp=temp->link;
		count++;
		}
	printf("Total no. of nodes is %d\n",count);
}

void insertfirst() {
	nd *temp,*ptr;
	temp=(nd*)malloc(sizeof(nd));
	printf("Enter the data : ");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(start==NULL)
		start=temp;
	else {
		temp->link=start;
		start=temp;
		}
	printf("Data Successfully Inserted\n");
}

void insertafternode() {
 	int n,c=0;
	printf("Enter the node after which you want to add element\n");
	scanf("%d",&n);
	int d;
	printf("Enter data\n");
	scanf("%d",&d);
	struct node *temp= (struct node*)malloc(sizeof(struct node));
	(*temp).data=d;
	if (start==NULL)
		{start=temp;
		temp->link=NULL;
	}
   	else{
   		struct node *prev,*x=start;
    			while (x!=NULL&& c!=n) {
 			       prev=x;
 			       x=x->link;
 			       c++;
 		   	}
 	   	prev->link=temp;
 	   	temp->link=x;
		printf("Data Successfully Inserted\n");
	}
}

void display() {
	nd *ptr;
	if(start==NULL)
		printf("List is empty\n");
	else {
		ptr=start;
		while(ptr!=NULL) {
			printf("\n%d",ptr->data);
			ptr=ptr->link;
		}
	}
	printf("\n");
}

void main() {
int ch,cont;
start=NULL;
do {
	printf("Choose your choice by pressing\n");
	printf("1 for insertlast\n");
	printf("2 for countnode\n");
	printf("3 for insertfirst\n");
	printf("4 for insertafternode\n");
	printf("5 for display\n");
	scanf("%d",&ch);
	switch(ch) {
		case 1:
		    insertlast();
		    break;
		case 2:
		    countnode();
		    break;
		case 3:
		    insertfirst();
		    break;
		case 4:
		    insertafternode();
		    break;
		case 5:
		    display();
		    break;
		default:
		    printf("Wrong choice\n");
		}
	printf("Do You want to Continue (1/0) : ");
	scanf("%d",&cont);
	if(cont!=1)
		cont=0;
	}while(cont);
}

