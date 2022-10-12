#include<stdio.h>
#include<stdlib.h>
int n,s[4],top=-1;
int push();
int pop();
int display();
int main()
{
    int c;
    char ch;
    printf("\nenter the number of elements:");
    scanf("%d",&n);
    do
    {
        printf("\nmenu driven program\n,1.push\n2.pop\n3.display\n4.exit\n");
        printf("enter your choice:\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            printf("\nend of program\n");
            exit(0);
            break;
            default:
            printf("\ninvalid input\n");
            exit(0);
            break;
        } printf("\ndo you want to continue(y/n)\n");
        scanf(" %c",&ch);
    }while( ch=='y'||ch=='Y');
}
int push()
{
    if(top==n-1)
    {
        printf("\nstack overflow\n");
        
    }
    else
    {
        int element;
        printf("\nenter the element to be inserted:");
        top=top+1;
        scanf("%d",&s[top]);
        
    }
}
int pop()
{
  if(top==-1)
  printf("\nstack underflow\n");
  else
  {
      printf("\n popped %d",s[top]);
      top=top-1;
  }
}
int display()
{
    int i;
    if(top==-1)
    printf("stack empty\n");
    else
    {
        for (i=top;i>=0;i--)
        printf("%d\t",s[i]);
    }
}