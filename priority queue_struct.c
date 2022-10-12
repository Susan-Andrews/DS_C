#include<stdio.h>
#include<stdlib.h>
int isempty();
int isfull();
void insert(int,int);
int highpriority();
int deletehighpriority();
void display();
int rear=-1;

 struct pqueue
{
    int ele;
    int priority;
}pq[5];
void main()
{ 
    int c,p,ele;
    char ch;
    do
    {
        printf("\nMenu driven program\n1.Insert\n2.Highest priority\n3.Delete\n4.Display\n5.exit");
        printf("\nEnter your choice:\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            if(isfull())
            printf("Priority Queue is full");
            else
            {
               printf("Enter the element to be inserted: ");
               scanf("%d",&ele);
               printf("Enter priority:");
               scanf("%d",&p);
               insert(ele,p);
               display();
            }
            break;
            case 2:
            if(isempty())
            printf(" Priority Queue is empty");
            else
            {
            p=highpriority();
            printf("\n High Priority =%d",p);
            }
            display();
            break;
            case 3:
            if(isempty())
            printf("Priority Queue is empty");
            else
            {
            ele=deletehighpriority();
            printf("\n %d is deleted",ele);
            }
            display();
            break;
            case 4:
            if(isempty())
            printf(" Priority Queue empty");
            else
            display();
            break;
            case 5:
            printf("\nEnd of program\n");
            exit(0);
            break;
            default:
            printf("\nInvalid input\n");
            exit(0);
            break;
        }
            printf("\nDo you want to continue(y/n)\n");
            scanf(" %c",&ch);
        
    }while( ch== 'y'|| ch== 'Y');
}

int isempty(){
    if(rear==-1){
        return 1;
    }
    else
    return 0;
}
 
int isfull(){
    if(rear==4){          //size is 5 so index upto 4
        return 1;
    }
    else
    return 0;
}
 
void insert(int ele,int p){
    rear=rear+1;
    pq[rear].ele=ele;
    pq[rear].priority=p;
}
 
int highpriority(){
    int i,p=-1;
    if(!isempty())
    {
        for(i=0;i<=rear;i++)
        {
            if(pq[i].priority>p)
            p=pq[i].priority;
        }

    }
    return p;
   
}
int deletehighpriority()
{
    int i,j,p,ele;
    p=highpriority();
    for(i=0;i<=rear;i++)
    {
        if(pq[i].priority==p)
        {
            ele=pq[i].ele;
            break;
        }
    }
    if(i<rear)
    {
        for(j=i;j<rear;j++)
        {
            pq[j].ele=pq[j+1].ele;
            pq[j].priority=pq[j+1].priority;
        }
    }
    rear=rear-1;
    return ele;
}
void display()
{
    int i;
    printf("\n Priority Queue =");
    for(i=0;i<=rear;i++)
    printf("\n | element=%d - priority=%d |\n",pq[i].ele,pq[i].priority);

}
 

   