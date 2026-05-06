#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int *a,n;
int partition(int low,int high)
{
  int i,j,p,temp;
  i=low;
  j=high + 1;
  p=a[low];
  while(i<=j)
  {
    do
    {
      i++;
    }while(p>=a[i]);
    do
    {
      j--;
    }while(p<a[j]);
    if(i<j)
    {
      temp=a[i];
      a[i]=a[j];
      a[j]=temp;
    }
  }
  temp=a[low];
  a[low]=a[j];
  a[j]=temp;
  return j;
}
void quicksort(int low, int high)
{
  int pi;
  if(low<high)
  {
    pi=partition(low,high);
    quicksort(low,pi-1);
    quicksort(pi+1,high);
  }
}
void main()
{
  int i;
  float start,end,complexity;
  printf("Enter the value of n:");
  scanf("%d",&n);
  a=calloc(n,sizeof(int));
  for(i=0;i<n;i++)
  {
    a[i]=rand()%100;
  }
  printf("The array is:\n");
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
  start=clock();
  quicksort(0,n-1);
  end=clock();
  printf("\nThe sorted array is:\n");
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
  complexity=(end-start)/CLOCKS_PER_SEC;
  printf("Complexity=%f\n",complexity);
}
