#include<stdio.h>
int qsort(int *,int ,int ,int );
void printArray(int *,int );
int div(int * ,int ,int );

int main()
{
	int i,j,n;
	printf("enter no. of elements - ");
	scanf("  %d",&n);
	int arr[n];
	printf("\nenter data - ");
	for(i=0;i<n;i++)
	{
	   scanf("  %d",&arr[i]);
    }
    printf("\n");
    qsort(arr,0,n-1,n);
    printf("\nsorted array is - ");
    printArray(arr,n);
    
    
}
int div(int a[],int left,int right)
 {
  	int pivot = a[right];
	int i = (left - 1);
	int j,temp;
	for (j = left; j <=right - 1; j++)
	{	
	if (a[j] <= pivot)
	   {
	     i++;
	   	 temp=a[i];
	   	 a[i]=a[j];
	   	 a[j]=temp;
 		 }
    }
	   temp=a[i+1];
	   a[i+1]=a[right];
	   a[right]=temp;
	   return (i + 1);
 }
 
 int qsort(int a[],int l,int r,int size)
 {
 	int d,j;
 	if(l<r)
 	{
 		d=div(a,l,r);
 		printArray(a,size);
 		qsort(a,l,d-1,size);
 		qsort(a,d+1,r,size);
 		
	 }
	
	 
 }
 void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}





















