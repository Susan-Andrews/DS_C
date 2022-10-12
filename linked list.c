#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
struct node *head;
void display();
void insertfront();
void insertend();
void insertposition();
void deletefront();
void deleteend();
void deleteposition();
void main ()
{
int choice;
while(choice)
{
printf("\nMenu driven program\n");
printf("Choose one operation on linked list \n");
printf("1.Display\n2.Insert at Beginning\n3.Insert at last\n4.Insert at any particular location\n5.Delete from Beginning\n6.Delete from last\n7.Delete node after specified location\n8.Exit\n");
printf("\nEnter your choice:\n");
scanf("\n%d",&choice);
switch(choice)
{
case 1:
display();
break;
case 2:
insertfront();
break;
case 3:
insertend();
break;
case 4:
insertposition();
break;
case 5:
deletefront();
break;
case 6:
deleteend();
break;
case 7:
deleteposition();
break;
case 8:
exit(0);
break;
default:
printf("Please enter valid choice..");
}
}
}
void insertfront()
{
struct node *ptr;
int item;
ptr = (struct node *) malloc(sizeof(struct node *));
if(ptr == NULL)
{
printf("\nOVERFLOW");
}
else
{
printf("Enter value\n");
scanf("%d",&item);
ptr->data = item;
ptr->next = head;
head = ptr;
printf("\nNode inserted");
}
}
void insertend()
{
struct node *ptr,*temp;
int item;
ptr = (struct node*)malloc(sizeof(struct node));
if(ptr == NULL)
{
printf("\nOVERFLOW");
}
else
{
printf("\nEnter value:\n");
scanf("%d",&item);
ptr->data = item;
if(head == NULL)
{
ptr -> next = NULL;
head = ptr;
printf("\nNode inserted");
}
else
{
temp = head;
while (temp -> next != NULL)
{
temp = temp -> next;
}
temp->next = ptr;
ptr->next = NULL;
printf("\nNode inserted");
}
}
}
void insertposition()
{
int i,loc,item;
struct node *ptr, *temp;
ptr = (struct node *) malloc (sizeof(struct node));
if(ptr == NULL)
{
printf("\nOVERFLOW");
}
else
{
printf("\nEnter element value");
scanf("%d",&item);
ptr->data = item;
printf("\nEnter the location after which you want to insert ");
scanf("\n%d",&loc);
temp=head;
for(i=0;i<loc;i++)
{
temp = temp->next;
if(temp == NULL)
{
printf("\ncan't insert\n");
return;
}
}
ptr ->next = temp ->next;
temp ->next = ptr;
printf("\nNode inserted");
}
}
void deletefront()
{
struct node *ptr;
if(head == NULL)
{
printf("\nList is empty\n");
}
else
{
ptr = head;
head = ptr->next;
free(ptr);
printf("\nNode deleted from the begining ...\n");
}
}
void deleteend()
{
struct node *ptr,*ptr1;
if(head == NULL)
{
printf("\nlist is empty");
}
else if(head -> next == NULL)
{
head = NULL;
free(head);
printf("\nlast node of the list deleted ...\n");
}
else
{
ptr = head;
while(ptr->next != NULL)
{
ptr1 = ptr;
ptr = ptr ->next;
}
ptr1->next = NULL;
free(ptr);
printf("\nDeleted Node from the last \n");
}
}
void deleteposition()
{
struct node *ptr,*ptr1;
int loc,i;
printf("\n Enter the position you want to delete\n");
scanf("%d",&loc);
ptr=head;
for(i=0;i<loc;i++)
{
ptr1 = ptr;
ptr = ptr->next;
if(ptr == NULL)
{
printf("\nCan't delete");
return;
}
}
ptr1 ->next = ptr ->next;
free(ptr);
printf("\nDeleted node : %d ",loc+1);
}
void display()
{
struct node *ptr;
ptr = head;
if(ptr == NULL)
{
printf("List is empty");
}
else
{
printf("\nprinting values : ");
while (ptr!=NULL)
{
printf("%d\t",ptr->data);
ptr = ptr -> next;
}
}
}