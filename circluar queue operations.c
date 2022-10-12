//  CODE     
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void insert ();
void deletion ();
void display ();
int cq[SIZE];
int front = -1;
int rear = -1;
int main ()
{
int item,c;
char ch;
do
{
printf (" MENU DRIVEN PROGRAM \n1.CENQUEUE\n2.CDEQUEUE\n3.DISPLAY\n");
printf ("Enter your choice : ");
scanf ("%d", &c);
switch (c)
{
case 1:
insert ();
display ();
break;
case 2:
deletion ();
display ();
break;
case 3:
display ();
break;
case 4:
printf ("end of program");
exit (0);
break;
default:
printf ("Wrong choice\n");
exit(0);
}printf("\ndo you want to continue(y/n):");
scanf(" %c",&ch);
}while( ch=='y'||ch=='Y');
return 0;
}
void insert ()
{
int item;
printf ("Input the element for insertion in queue : ");
scanf ("%d", &item);
if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
{
printf ("Queue Overflow \n");
return;
}
if (front == -1)
{
front = 0;
rear = 0;
}
else
{
if (rear == SIZE - 1)
rear = 0;
else
rear = rear + 1;
}
cq[rear] = item;
}
void deletion ()
{
if (front == -1)
{
printf ("Queue Underflow\n");
return;
}
else
printf ("Element deleted from CQueue is : %d\n", cq[front]);
if (front == rear)
{
front = -1;
rear = -1;
}
else
{
if (front == SIZE - 1)
front = 0;
else
front = front + 1;
}
}
void display ()
{
int fp = front, rp = rear;
if (front == -1)
{
printf ("CQueue is empty\n");
return;
}
printf ("CQueue elements : ");
if (fp <= rp)
while (fp <= rp)
{
printf ("%d ", cq[fp]);
fp++;
}
else
{
while (fp <= SIZE - 1)
{
printf ("%d ", cq[fp]);
fp++;
}
fp = 0;
while (fp <= rp)
{
printf ("%d ", cq[fp]);
fp++;
} }
printf ("\n");
}