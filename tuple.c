#include<stdio.h>
void v(int a[10][10],int m,int n,int s[][3]);
void  t(int a[][10], int b[][10],int sp1[][3], int sp2[][3],int sp3[][3],int m, int n);
void  add(int a[][10], int b[][10],int sp1[][3], int sp2[][3],int sp3[][3],int m, int n);
int main()
{
    int a[10][10],b[10][10],sp1[10][3],sp2[10][3],sp3[10][3],m,n,t1,t2,i,j,k,c;
    printf("enter the rows and columns of m");
    scanf("%d%d",&m,&n);
    printf("enter the elements of the first matrix");
    for(i=0;i<m;i++)
    {
    for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }    
    v(a,m,n,sp1);
    printf("enter the elements of the second matrix");
    
     for(i=0;i<m;i++)
     {
        for(j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
     }
    v(b,m,n,sp2);
    do
    {
        printf("1.trans\n2.add\n");
        printf("enter choice");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            t(a,b,sp1,sp2,sp3,m,n);
            break;
            case 2:
            add(a,b,sp1,sp2,sp3,m,n);
            break;
            default:
            printf("invalid");  
            break;
         }
}while(c<3);
}
void  v(int a[][10],int m,int n,int s[][3])
 {
     int k=1;
     int i,j;
     for(i=0;i<m;i++)
     {
         for(j=0;j<n;j++)
         {
             if(a[i][j]!=0)
             {
                 s[k][0]=i;
                 s[k][1]=j;
                 s[k][2]=a[i][j];
                 k=k+1;
             }
         }
     }
     s[0][0]=m;
     s[0][1]=n;
     s[0][2]=k-1;
     printf("corres tuple matrix is:\n");
     for(i=0;i<k;i++)
     {
         for(j=0;j<3;j++)
         {
             printf("%d ",s[i][j]);

         }
         printf("\n");
     }
}
void t(int a[][10], int b[][10],int sp1[][3], int sp2[][3],int sp3[][3],int m, int n)
{
    int i,j,k;
    sp3[0][0]=sp1[0][1];
            sp3[0][1]=sp1[0][0];
            sp3[0][2]=sp1[0][2];
            k=1;
            for(i=0;i<sp1[0][1];i++)
              for(j=1;j<=sp1[0][2];j++)
                 if(i==sp1[j][1])
                 {
                        sp3[k][0]=i;
                        sp3[k][1]=sp1[j][0];
                        sp3[k][2]=sp1[j][2];
                        k++;
                 }
            printf("transpose  of first tuple is\n");
            for(i=0;i<k;i++)
            {
                for(j=0;j<3;j++)
                {
                    printf("%d ",sp3[i][j]);
                }
                printf("\n");
            }
            sp3[0][0]=sp2[0][1];
            sp3[0][1]=sp2[0][0];
            sp3[0][2]=sp2[0][2];
            k=1;  
            for(i=0;i<sp2[0][1];i++)
                for(j=1;j<=sp2[0][2];j++)
                {
                    if(i==sp2[j][1])
                    {
                        sp3[k][0]=i;
                        sp3[k][1]=sp2[j][0];
                        sp3[k][2]=sp2[j][2];
                        k++;
                    }
                }
                printf("transpose  of sec tuple is\n");
                    for(i=0;i<k;i++)
                    {
                      for(j=0;j<3;j++)
                       {
                         printf("%d",sp3[i][j]);
                       }
                        printf("\n");
}
    
}
void add(int a[][10], int b[][10],int sp1[][3], int sp2[][3],int sp3[][3],int m, int n)
{
    int i,j,k;
    int t1,t2;
                t1=sp1[0][2];
                t2=sp2[0][2];
                sp3[0][0]=m;
                sp3[0][1]=n;
                i=j=k=1;
                while(i<=t1 && j<=t2)
                {
                    if(sp1[i][0]<sp2[j][0])
                    {
                        sp3[k][0]=sp1[i][0];
                        sp3[k][1]=sp1[i][1];
                        sp3[k][2]=sp1[i][2];
                        i++;k++;
                    }
                    else if (sp1[i][0]>sp2[j][0])
                    {
                        sp3[k][0]=sp2[j][0];
                        sp3[k][1]=sp2[j][1];
                        sp3[k][2]=sp2[j][2];
                        j++;k++;
                    }
                    else if ((sp1[i][0]==sp2[j][0])&& (sp1[i][1]==sp2[j][1]))
                        {
                            sp3[k][0]=sp1[i][0];
                            sp3[k][1]=sp1[i][1];
                            sp3[k][2]=sp1[i][2]+sp2[j][2];
                            i++;k++;j++;
                        
                        }
                    else if( ( sp1[i][0]==sp2[i][0])&&(sp1[i][1]<sp2[j][1]))
            {
                sp3[k][0]=sp1[i][0];
                sp3[k][1]=sp1[i][1];
                sp3[k][2]=sp1[i][2];
                i++;k++;  
            }
                    else if ( ( sp1[i][0]==sp2[j][0])&&(sp1[i][1]>sp2[j][1]))
            {
                sp3[k][0]=sp2[j][0];
                sp3[k][1]=sp2[j][1];
                sp3[k][2]=sp2[j][2];
                j++;k++;  
           
            } 
                }  
    
                while(i<=t1)
        {
            
                sp3[k][0]=sp1[i][0];
                sp3[k][1]=sp1[i][1];
                sp3[k][2]=sp1[i][2];
                i++;k++;  
           
        }
                while(j<=t2)
        {
            
                sp3[k][0]=sp2[j][0];
                sp3[k][1]=sp2[j][1];
                sp3[k][2]=sp2[j][2];
                j++;k++;  
           
        }
                sp3[0][2]=k-1;
                printf("resu tuple m is \n");
                for(i=0;i<k;i++)
                {
                for(j=0;j<3;j++)
                  {
                    printf("%d",sp3[i][j]);
                }
                printf("\n");
                }
}