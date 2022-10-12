#include<stdio.h>
int  printpoly(int n, int p[][2]);
int polyadd(int p1[][2],int p2[][2],int p[][2],int n1,int n2);
void main()
{
    int p1[6][2],p2[6][2],p[12][2],t1,t2,i,j,k;
    printf("enter the no of terms");
    scanf("%d",&t1);
    printf("enter the no of terms");
    scanf("%d",&t2);
    printf("enter the coeffe and expo of first");
    for(i=0;i<t1;i++)
    {
        scanf("%d%d",&p1[i][0],&p1[i][1]);
    }
    printf("enter the coeffe and expo of sec");
    for(i=0;i<t2;i++)
    {
        scanf("%d%d",&p2[i][0],&p2[i][1]);
    }
    printf("poly are:");
    printpoly(t1,p1);
    printf("\n");
    printpoly(t2,p2);
    printf("\n");
    printf("resultant poly:");
    k=polyadd(p1,p2,p,t1,t2);
    printpoly(k,p);
}
int polyadd(int p1[][2],int p2[][2],int p[][2],int n1,int n2)
{
    int i=0;
    int j=0;
    int k=0;
    while(i<n1 && j<n2)
    {
        if(p1[i][1]==p2[j][1])
        {
            p[k][1]=p1[i][1];
            p[k][0]=p1[i][0]+p2[j][0];
            i++;j++;k++;

        }
        else if(p1[i][1]>p2[j][1])
        {
            p[k][1]=p1[i][1];
            p[k][0]=p1[i][0];
            i++;k++;
        }
        else {
        p[k][1]=p2[j][1];
        p[k][0]=p2[j][0];
        j++;k++;
    }
    }
    while(i<n1)
    {
        p[k][1]=p1[i][1];
        p[k][0]=p1[i][0];
        i++;k++;
    }
    while(j<n2)
    {
        p[k][1]=p2[j][1];
        p[k][0]=p2[j][0];
        j++;k++;
    }
    return k;
    }
int printpoly(int n,int p[][2])
    {
        int i;
        for(i=0;i<n;i++)
        {
            printf("%d",p[i][0]);
            if(p[i][1]>0)
            {
                printf("X");
                if(p[i][1]>1)
                {
                    printf("^%d",p[i][1]);
                    
                }
            }
            printf("+");
         
        }
           printf("\b ");
    }
////////////////////////////////
#include<stdio.h>

 struct node
 {
     int coeff;
     int exp;
     struct node *next;
 };

 void insert(struct node **head,int c,int e)
 {
     struct node *temp,*current,*prev;
     if(*head==NULL)
     {
         temp=(struct node *)malloc(1*sizeof(struct node));
         temp->coeff=c;
         temp->exp=e;
         temp->next=NULL;
         *head=temp;
     }
     else
     {
         current=*head;
         while(current!=NULL)
         {
             prev=current;
             current=current->next;
         }
         if(current==NULL)
         {
             temp=(struct node *)malloc(1*sizeof(struct node));
             temp->coeff=c;
             temp->exp=e;
             temp->next=NULL;
             prev->next=temp;
         }
     }
 }

 void traverse(struct node *start)
 {
     struct node *temp;
     temp=start;
     if (temp==NULL)
     printf("Empty polynomial\n");
     else
     {
         while(temp!=NULL)
         {
             printf("%dx^%d ",temp->coeff,temp->exp);
             if(temp->next!=NULL)
             {
                printf("+ ");
             }
             temp=temp->next;
         }
         printf("\n");
     }
 }

 void add(struct node **p1head,struct node **p2head,struct node **Rhead)
 {
     struct node *p1current,*p2current,*Rcurrent,*Rprev;
     p1current=*p1head;
     p2current=*p2head;
     *Rhead=NULL;
     Rcurrent=NULL;
     Rprev=NULL;
     int c,e;
     while(p1current!=NULL || p2current!=NULL)
     {
         if(p1current!=NULL && p2current!=NULL)
         {
             if(p1current->exp==p2current->exp)
             {
                 c=p1current->coeff+p2current->coeff;
                 e=p1current->exp;
                 insert(Rhead,c,e);
                 p1current=p1current->next;
                 p2current=p2current->next;
             }
             else if(p1current->exp>p2current->exp)
             {
                 c=p1current->coeff;
                 e=p1current->exp;
                 insert(Rhead,c,e);
                 p1current=p1current->next;
             }
             else if(p2current->exp > p1current->exp)
             {
                 c=p2current->coeff;
                 e=p2current->exp;
                 insert(Rhead,c,e);
                 p2current=p2current->next;
             }

         }
         else if(p1current!=NULL)
         {
             c=p1current->coeff;
             e=p1current->exp;
             insert(Rhead,c,e);
             p1current=p1current->next;
         }
         else if(p2current!=NULL)
         {
             c=p2current->coeff;
             e=p2current->exp;
             insert(Rhead,c,e);
             p2current=p2current->next;
         }
         else
         {
            exit(0);
         }
     }
 }

 void main()
 {
     struct node *p1=NULL,*p2=NULL,*r=NULL;
     int i,n,c,e;

     //Inputting terms of polynomial 1
     printf("Polynomial 1\n");
     printf("Enter number of terms:");
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
         printf("Enter coefficient:");
         scanf("%d",&c);
         printf("Enter exponent:");
         scanf("%d",&e);
         insert(&p1,c,e);
     }

     //Inputting terms of polynomial 2
     printf("Polynomial 2\n");
     printf("Enter number of terms:");
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
         printf("Enter coefficient:");
         scanf("%d",&c);
         printf("Enter exponent:");
         scanf("%d",&e);
         insert(&p2,c,e);
     }

     //Printing the polynomials
     printf("\nFirst polynomial:\n");
     traverse(p1);
     printf("Second Polynomial:\n");
     traverse(p2);
     //Printing the polynomial after addition
     add(&p1,&p2,&r);
     printf("Added Polynomial: \n");
     traverse(r);
 }