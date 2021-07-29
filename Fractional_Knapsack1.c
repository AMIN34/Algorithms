#include<stdio.h>
#include<stdlib.h>
struct sack
{
    int wt,val;
    double ratio;  // ratio = val/wt
};


void sort(struct sack a[],int n)
{
    struct sack temp;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(a[i].ratio<a[j].ratio)
            {
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
}

int main()
{
    int n,curr_Capacity;

    //For Console Input
    printf("Enter number of items: ");
    scanf("%d",&n);
    struct sack *a=(struct sack *)malloc(sizeof(struct sack)*n);
    printf("\nEnter the weight and value of the items: \n");
    for(int i=0;i<n;++i){
        scanf("%d",&a[i].wt);
        scanf("%d",&a[i].val);
        a[i].ratio=(double)a[i].val/(double)a[i].wt;
    }

    // For file input
    /* FILE *fp;
    fp= fopen("f_kp.txt","r");
    if(fp==NULL){
        puts("cannot open file");
        exit(1);
    }
    fscanf(fp,"%d",&n);
    printf("No. of items: %d",n);
    struct sack *a=(struct sack *)malloc(sizeof(struct sack)*n);
    for(int i=0;i<n;++i)
    {
        fscanf(fp,"%d",&a[i].wt);
        fscanf(fp,"%d",&a[i].val);
        a[i].ratio=(double)a[i].val/(double)a[i].wt;
    }  */

    printf("\nEnter Capacity: ");
    scanf("%d",&curr_Capacity);
    
    printf("\nWeight and Value :\n");
    for(int i=0;i<n;++i)
    {
        printf("%d %d",a[i].wt,a[i].val);
        printf("\n");
    } 

    sort(a,n);
    /* printf("\n");
    for(int i=0;i<n;++i)
    {
        printf("%d %d",a[i].wt,a[i].val);
        printf("\n");
    }  */
    
    double res=0.0;
    for(int i=0;i<n;++i)
    {
        if(a[i].wt<=curr_Capacity)
        {
            res+=a[i].val;
            printf("\nWeight taken:%d ",a[i].wt);
            printf("\nIntermedaite Profit %d: %.2lf",i+1,res);
            /* printf(":");
            printf(" %.2lf",res); */
            curr_Capacity-=a[i].wt;
            printf("\nRemaining Capacity: %d",curr_Capacity);
            printf("\n");
        }
        else
        {
            res+=a[i].val*((double)curr_Capacity/(double)a[i].wt);
            printf("\nWeight taken:%.2lf ",(double)curr_Capacity);
            printf("\nIntermedaite Profit %d: %.2lf",i+1,res);
            /* printf(":");
            printf(" %.2lf",res); */
            printf("\nRemaining Capacity: 0");
            break;
        }
    }
    printf("\n\nFinal profit: %.2lf",res);
    return 0;
}