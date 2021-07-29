#include<stdio.h>
void binarySearch(int low,int high, int a[]){
    int num,mid,fl=0;
    printf("\nEnter number to be searched: ");
    scanf("%d",&num);
    printf("\n");
    while(low<=high)
    {
        mid=(low+high)/2;
        printf("Mid element:- %d\n",a[mid]);
        if(a[mid]==num)
        {
            fl=1;
            break;
        }
        else if(a[mid]<num)
            low=mid+1;
        else if(a[mid]>num)
            high=mid-1;
    }
    if(fl==1)
        printf("Element found at position %d",mid+1);
    else
        printf("Element not found");
}

int main(){
    int n,i;
    printf("Enter array size: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of array: ");
    for(i=0;i<n;++i)
        scanf("%d",&a[i]);
    binarySearch(0,n-1,a);
    return 0;
}