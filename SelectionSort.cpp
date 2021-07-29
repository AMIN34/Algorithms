#include<bits/stdc++.h>
using namespace std;

void selectionSort(int n, int a[])
{
    int i,j,pos,temp;

    for(i=0;i<n-1;++i)
    {
        pos=i;
        for(j=i+1;j<n;++j)
        {
            if(a[j]<a[pos])
                pos=j;
        }
        temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;
    }
    cout<<"Sorted array: ";
    for(i=0;i<n;++i)
        cout<<a[i]<<" ";
}

int main()
{
    int n,i;
    cout<<"Enter array size:";
    cin>>n;
    int a[n];
    cout<<"Enter array: ";
    for(i=0;i<n;++i)
        cin>>a[i];
    
    selectionSort(n,a);
    return 0;
}