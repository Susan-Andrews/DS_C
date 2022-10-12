#include<stdio.h>
void quicksort (int a[10], int firstend, int lastend);
void display (int a[], int n);
int main ()
{
int a[10], i, n;
printf ("enter size of array");
scanf ("%d", &n);
printf ("enter elements");
for (i = 0; i < n; i++)
{
scanf ("%d", &a[i]);
}
quicksort (a, 0, n - 1);
display (a, n);
return 0;
}
void quicksort (int a[10], int firstend, int lastend)
{
int leftpointer, rightpointer, pivot, temp;
if (firstend < lastend)
{
pivot = firstend;
leftpointer = firstend;
rightpointer = lastend;
while (leftpointer < rightpointer)
{
while (a[leftpointer] <= a[pivot] && leftpointer < lastend)
leftpointer++;
while (a[rightpointer] > a[pivot])
rightpointer--;
if (leftpointer < rightpointer)
{
temp = a[leftpointer];
a[leftpointer] = a[rightpointer];
a[rightpointer] = temp;
}
}
temp = a[pivot];
a[pivot] = a[rightpointer];
a[rightpointer] = temp;
quicksort (a, 0, rightpointer - 1);
quicksort (a, rightpointer + 1, lastend);
}
}
void  display (int a[], int n)
{
int i;
printf (" sorted elements are: ");
for (i = 0; i < n; i++)
{
printf ("%d\t", a[i]);
}
}