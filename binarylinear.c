#include <stdio.h>
#include<stdlib.h>
int array[8];
int low;
int high;
int binarySearch();
int linearsearch();
int main()
{
    int c;
    do{
        printf("menu driven program");
        printf("enter any choice");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            binarySearch();
            break;
            case 2:
            linearsearch();
            break;
            case 3:
            printf("end of program");
            exit(0);
            break;
          
        }
    }while(c<4);
}

int binarySearch() {
int i,n,mid,key;
printf("Enter number of elements\n");
scanf("%d",&n);
printf("Enter %d integers\n", n);
for(i = 0; i < n; i++)
scanf("%d",&array[i]);
printf("Enter value to find\n");
scanf("%d", &key);
low = 0;
high = n - 1;
mid = (low+high)/2;
while (low <= high) {
if(array[mid] < key)
low = mid + 1;
else if (array[mid] == key) {
printf("%d found at location %d\n", key, mid+1);
break;
}
else
high = mid - 1;
mid = (low + high)/2;
}
if(low > high)
printf("Not found! %d isn't present in the list\n", key);
return 0;
  }
 int linearsearch()
{
    int a[20],i,x,n;
    printf("How many elements?");
    scanf("%d",&n);
     
    printf("Enter array elements:n");
    for(i=0;i<n;++i)
        scanf("%d",&a[i]);
     
    printf("nEnter element to search:");
    scanf("%d",&x);
     
    for(i=0;i<n;++i)
        if(a[i]==x)
            break;
     
    if(i<n)
        printf("Element found at index %d",i);
    else
        printf("Element not found");
        return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                        SUSAN ANDREWS:62

#include <stdio.h>
int binarySearch(int a[],int low,int high,int mid,int key,int n);
int main()
{
    int a[8],i,n,low,high,key,mid;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter %d integers in sorted manner:\n", n);
    for(i = 0; i < n; i++)
    scanf("%d",&a[i]);
    printf("Enter value to find:");
    scanf("%d", &key);
    binarySearch(a,low,high,mid,key,n);
}
int binarySearch(int a[8],int low,int high,int mid,int key,int n) 
{
    int i;
    low = 0;
    high = n - 1;
    mid = (low+high)/2;
    while (low <= high) {
    if(a[mid] < key)
    low = mid + 1;
    else if (a[mid] == key) {
    printf("%d found at location %d\n", key, mid);
    break;
    }
    else
    high = mid - 1;
    mid = (low + high)/2;
    }
    if(low > high)
    printf("Not found! %d isn't present in the list\n", key);
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
int a[8];
int linearsearch(int a[],int n,int x);
int main()
{
    int  a[8],i,x,n;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i=0;i<n;++i)
    scanf("%d",&a[i]);
    printf("Enter element to search:");
    scanf("%d",&x);
    linearsearch(a,n,x);
}


 int linearsearch(int a[8],int n,int x)
{
    int i;
    for(i=0;i<n;++i)
        if(a[i]==x)
            break;
    if(i<n)
        printf("Element %d found at index %d",x,i);
    else
        printf("Element not found");
        return 0;
}