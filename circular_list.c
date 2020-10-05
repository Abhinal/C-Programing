/***

Name: Abhinav Agarwal
Dept: CSE 2nd Year
Roll: 01

Write a menu driven program in C which will perform the following operations on Circular Linked List.

	i)   create a circular linked list
	ii)  insert a node at the beginning
	iii) insert a node at the end
	iv)  delete a node at the front
	v)   delete a node at the end
	vi)  delete the circular list
	vii) display the list


***/

#include<stdio.h>
#include<stdlib.h>
typedef struct circular
{
int data;
struct circular *next;
}node;
node *start;
void create()
{
int i,data,n;
printf("Enter the no. of nodes to create:");
scanf("%d",&n);
node *newnode,*prevnode;
prevnode=NULL;
for(i=1;i<=n;i++)
{
newnode=(node*)malloc(sizeof(node));
printf("Enter data of %d node:",i);
scanf("%d",&data);
newnode->data=data;
newnode->next=NULL;
if(prevnode!=NULL)
   prevnode->next=newnode;
if(start==NULL)
    start=newnode;
prevnode=newnode;
}
prevnode->next=start;
printf("\nCircular linked list is created\n");
}
void insertbeg()
{
node *temp,*ptr;
temp=(node*)malloc(sizeof(node));
printf("Enter the data");
scanf("%d",&temp->data);
temp->next=NULL;
if(start==NULL)
{
start=temp;
temp->next=start;
}
else
{
ptr=start;
while(ptr->next!=start)
ptr=ptr->next;
temp->next=start;
start=temp;
ptr->next=start;
}
}
void insertend()
{
node *temp,*ptr;
temp=(node*)malloc(sizeof(node));
printf("Enter the data:");
scanf("%d",&temp->data);
temp->next=NULL;
if(start==NULL)
{
start=temp;
temp->next=start;
}
else
{
ptr=start;
while(ptr->next!=start)
ptr=ptr->next;
ptr->next=temp;
temp->next=start;
}
}
void deletefront()
{
node *ptr;
if(start==NULL)
printf("\nUNDERFLOW\n");
else if(start->next==start)
start=NULL;
else
{
ptr=start;
while(ptr->next!=start)
ptr=ptr->next;
start=start->next;
ptr->next=start;
}
}
void deleteend()
{
node *ptr;
if(start==NULL)
printf("\nUNDERFLOW\n");
else if(start->next==start)
start=NULL;
else
{
ptr=start;
while(ptr->next->next!=start)
ptr=ptr->next;
ptr->next=start;
}
}
void deleteCLL()
{
start=NULL;
}
void display()
{
node *ptr;
if(start==NULL)
printf("\n List is empty");
else
{
ptr=start;
while(ptr->next!=start)
{
printf("\n%d",ptr->data);
ptr=ptr->next;
}
printf("\n%d",ptr->data);
}
}
int main()
{
int ch;
start=NULL;
while(1)
{
printf("\n 1 for create");
printf("\n 2 for insert at beginning");
printf("\n 3 for insert at end");
printf("\n 4 for delete at front");
printf("\n 5 for delete at end");
printf("\n 6 for delete circular list");
printf("\n 7 for display");
printf("\n 8 for exit");
printf("\n\n Enter the choice");
scanf("%d",&ch);
switch(ch)
{
case 1:
       create();
       break;
case 2:
       insertbeg();
       break;
case 3:
       insertend();
       break;
case 4:
       deletefront();
       break;
case 5:
       deleteend();
       break;
case 6:
       deleteCLL();
       break;
case 7:
       display();
       break;
case 8:
       exit(1);
default:
       printf("\nWrong choice");
}
}
}
