//                                          SUSAN ANDREWS : 62

#include<stdio.h>
#include <stdlib.h>
int dq[5];
int rear=-1;
int front=-1;
int isfull();
int isempty();
int addfront(int);
int deletefront();
int addrear(int);
int deleterear();
void display();

int main()
{
    int n,ele;
    int c;
    char ch;
    do
    {
        printf("\nmenu driven program\n1.Insert through front \n2. delete through front \n3.add  through rear \n4.Delete through rear \n5.display\n6.exit");
        printf("\nEnter your choice:\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            if(isfull())
            printf("Deque is full");
            else
            {
                printf("Enter element to insert");
                scanf("%d",&ele);
                addfront(ele);
            }
            display();
            break;
            case 2:
            if(isempty())
            printf("Deque is empty");
            else{
                ele=deletefront();
                printf(" %d  is deleted ",ele);
            }
            display();
            break;
            case 3:
            if(isfull())
            printf("Deque is full");
            else
            {
                printf("Enter element to insetrt");
                scanf("%d",&ele);
                addrear(ele);
            }
            display();
            break;
            case 4:
            if(isempty())
            printf("Deque is empty");
            else{
                ele=deleterear();
                printf(" %d  is deleted ",ele);
            }
            display();
            break;
            case 5:
           if(isempty())
            printf("Deque is empty");
            else 
              display();
            break;
            case 6:
            printf("\nEnd of program\n");
            exit(0);
            default:
            printf("\nInvalid input\n");
            exit(0);
            break;
        } printf("\nDo you want to continue(y/n)\n");
        scanf(" %c",&ch);
    }while( ch=='y'||ch=='Y');
}
int isfull()
{
    if(((front==0) && (rear==4)) || (front==rear+1))
    return 1;
    else
    return 0;
}
int isempty()
{
    if(front==-1)
    return 1;
    else
    return 0;

}
int addfront(int ele)
{
    int i;
    if (front==-1)
    {
        front=0;
        rear=0;
        dq[front]=ele;
    }
    else if(front>0)
    {
    front=front-1;
    dq[front]=ele;
    }
    else 
    {
    i=rear;
    while(i>=front)
    {
        dq[i+1]=dq[i];
        i=i-1;
    }
    dq[front]=ele;
    rear=rear+1;
    }
    }
int deletefront()
{
    int ele;
    ele=dq[front];
    dq[front]=0;
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    front=front+1;
    return ele;

}
int addrear(int ele)
{
    int i;
    if(front==-1)
    {
        front=0;
        rear=0; 
        dq[front]=ele;
    }
    else if(rear<5)
    {
    rear=rear+1;
    dq[rear]=ele;
    }
    else
    {
        i=front;
        while(i<=rear)
        {
            dq[i-1]=dq[i];
            i=i+1;
        }
        dq[rear]=ele;
        front=front-1;
    }
}
int deleterear()
{
    int ele;
    ele=dq[rear];
    if(front==rear)  //last element
    {
        front=-1;
        rear=-1;
    }
    else 
    rear=rear-1;
    return ele;
}

void display()
{
    int i;
    i=front;
    printf("elements of Deque are :");
    while(i<=rear)
    {
        printf( " %d " ,dq[i]);
        i=i+1;
    }
    
}