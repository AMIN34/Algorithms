#include<stdio.h>
void merge(int a[],int lb,int mid, int ub){
    int i,j,k,b[50],x;
    i=lb;
    k=lb;
    j=mid+1;
    while(i<=mid && j<=ub){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
            k++;
        }
        else{
            b[k]=a[j];
            k++;
            j++;
        }
    }
    if(i>mid){
        while(j<=ub){
            b[k]=a[j];
            k++;
            j++;
        }
    }
    else{
        while(i<=mid){
            b[k]=a[i];
            k++;
            i++;
        }
    }
    for(k=lb;k<=ub;k++)
        a[k]=b[k];
    // printf("\nElements after merging are: ");
    printf("\n");
    printf("[");
    for(x=lb;x<=ub;x++)
        printf("%d, ",a[x]);
    printf("]");
}
void mergesort(int a[],int lb,int ub){
    /*int i;
    printf("\nElements before merging are: ");
    printf("\n");
    for(i=lb;i<=ub;i++)
        printf("%d ",a[i]); */
    if(lb<ub) {
        int mid;
        mid=(ub+lb)/2;
        mergesort(a,lb,mid); 
        mergesort(a,mid+1,ub); 
        merge(a,lb,mid,ub);
    }
}
int main(){
    int i,n;

    printf("Enter array size:");
    scanf("%d",&n);
    
    int a[n];
    printf("Enter array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    printf("\nGiven Array: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    
    printf("\nSorting:");
    mergesort(a,0,n-1);
    
    printf("\nSorted array:");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}