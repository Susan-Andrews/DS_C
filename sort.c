#include<stdio.h>
#include<stdlib.h>
void bubble(int a[10],int n);
void insertion(int a[10],int n);
void selection(int a[10],int n);
void display(int a[10],int n);
void main(){
    int a[10],i,n,c;
    char ch;
    printf("enter the number of elements in array:");
    scanf("%d",&n);
    printf("enter the elements");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    do{
        printf("enter your choice: 1.bubble 2.insertion, 3.selection 4.exit");
        scanf("%d",&c);
        switch(c){
            case 1:
            bubble(a,n);
            display(a,n);
            break;
            case 2:
            insertion(a,n);
            display(a,n);
            break;
            case 3:
            selection(a,n);
            display(a,n);
            break;
            case 4:
            exit(0);
            break;
            
        }
        printf("\nDo you want to continue:");
        scanf(" %c",&ch);
        
    }while(ch=='Y' || ch=='y' );
}
void bubble(int a[],int n)
{
   
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void selection(int a[],int n)
{
    int i,j,min,temp;
     for (i = 0; i < (n - 1); i++) {
      min = i;
      for (j = i + 1; j < n; j++) {
         if (a[min] > a[j])
            min = j;
      }
      if (min != i) {
         temp = a[i];
         a[i] = a[min];
         a[min] = temp;
      }
   }  
}
void insertion(int a[],int n)
{
    int i,j,min;
    for(i=1;i<n;i++)
    {
        min=a[i];
        j=i-1;
        while(min<a[j] && j>=0)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=min;
    }
}
void display(int a[],int n)
{
    for( int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}