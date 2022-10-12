#include<stdio.h>
#include<stdlib.h>
int display(int ar[],int n);
int insert(int ar[], int n);
 int deleting(int ar[],int n);
 int search(int ar[],int n);

int main()
{
	int ar[50],n,i,nm,choice;
	char ch;	
	printf("Enter the number of elements:  ");
	scanf("%d",&n);
	printf("enter the elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&ar[i]);
	display(ar,n);
	do
	{
	printf("\nARRAY OPERATIONS ARE : \n1 :INSERTION \n2:DELETION \n3:SEARCH\n4:DISPLAY\n5:EXIT\n");
	printf("\nEnter any choice\n");
		scanf("%d",&choice);
	
switch(choice)
{
	case 1:
	            insert(ar,n);
	            n++;
	            printf("after insertion:\n");
	            display(ar,n);
	            break;
	case 2:     
	           deleting(ar,n);
	           n--;
	            printf("after deletion:");
			    display(ar,n);
			    break;
	case 3:
				search(ar,n);
				 display(ar,n);
		         break;
	case 4:printf("The elements in the array are\n");
	              display(ar,n);
	              break;
	              case 5 :
	              printf("END OF PROGRAM! THANK YOU!\n");
	    break;      
	default:
	printf("Wrong choice\n") ;
	             exit(0);
	             break;
}
printf("\nDo you want to continue?(Y/N)\n");
scanf("%s",&ch); 
}while(ch=='y'||ch=='Y');
  }
  int display(int ar[],int n)
  {
      printf("\nelements are:");
      int i;
   for(i=0;i<n;i++)
	            printf("%d\t",ar[i]);
	          
  }
  int insert(int ar[], int n)
  {
     
    int i,ind,nm;
    printf("enter the number to be inserted: ");
	            scanf("%d",&nm);
	            printf("enter the index to where to add: ");
	            scanf("%d",&ind);
  	for(i=n;i>ind;i--)
	   {
	        ar[i]=ar[i-1];
	   }
	        ar[ind]=nm;
	        return 1;
	     
  }
  int deleting(int ar[],int n)
  {
      int nm,i;
              printf("enter the index of number  to be deleted: ");
	            scanf("%d",&nm);
	            
	            for(i=nm;i<n-1;i++)
	            
	            {
				ar[i]=ar[i+1];
			    
	            }
	            
  }
  int search(int ar[],int n)
  {
  	   int nm,i;
  printf("enter the value to be searched");
	            scanf("%d",&nm);
	          int   ct=0;
	            for(i=0;i<n;i++)
	             {
					 if( ar[i]==nm)
					 {
						 printf("value found at index %d\n",i);
						 ct++;
				      }
				}
				if(ct==0)
				printf("value not found\n");
  }
