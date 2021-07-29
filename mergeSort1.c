#include<stdio.h>

void mergesort(int a[],int lb,int ub)
{
    int i;
    printf("\nIntermediate array elements before merging are:\n");
  for(i=lb;i<=ub;i++)
  {
      printf("%d ",a[i]);
  }
    if(lb<ub) //until we get single element array
    {
        int mid;
        mid=(ub+lb)/2;
        mergesort(a,lb,mid); //first sub array from start to middle element
        mergesort(a,mid+1,ub); //second sub array from mid+1 to ub
        merge(a,lb,mid,ub);
    }
}

void merge(int a[],int lb,int mid, int ub)
{
    int i,j,k,b[20],x;
    i=lb;
    k=lb;
    j=mid+1;
    while(i<=mid && j<=ub)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }
    else
        {
            while(i<=mid)
            {
                b[k]=a[i];
                k++;
                i++;
            }
        }
        for(k=lb;k<=ub;k++)
            a[k]=b[k];
            printf("\nIntermediate array elements after merging are:\n");
  for(x=lb;x<=ub;x++)
  {
      printf("%d ",a[x]);
  }

}

int main()
{
  int a[20],i,n;
  printf("Enter array size:");
  scanf("%d",&n);
  printf("\nEnter array elements: ");
  for(i=0;i<n;i++)
      scanf("%d",&a[i]);
  mergesort(a,0,n-1);
  printf("\nFinally The array elements are:\n");
  for(i=0;i<n;i++)
  {
      printf("%d ",a[i]);
  }
  return 0;
}