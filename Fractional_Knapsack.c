#include<stdio.h>
#include<stdlib.h>
struct sack {
    int wt,val;
};


void sort(struct sack a[],int n) {
    struct sack obj1,obj2;
    double d1=(double) obj1.val/(double)obj1.wt;
    double d2=(double) obj2.val/(double)obj2.wt;
    
    struct sack temp;
    for(int i=0;i<n-1;++i) {
        for(int j=0;j<n-i-1;++j) {
            if(d1<d2) {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

int main()
{
    int n,curr_Capacity;
    printf("Enter number of items: ");
    scanf("%d",&n);
    struct sack *a=(struct sack *)malloc(sizeof(struct sack)*n);
    printf("\nEnter the weight and value of the items: \n");
    for(int i=0;i<n;++i){
        scanf("%d",&a[i].wt);
        scanf("%d",&a[i].val);
    }
    printf("Enter capacity of Knapsack: ");
    scanf("%d",&curr_Capacity);

    /* FILE *fp;
    fp= fopen("f_kp.txt","r");
    if(fp==NULL){
        puts("cannot open file");
        exit(1);
    }
    fscanf(fp,"%d",&n);
    printf("No. of items: %d",n);
    struct sack *a=(struct sack *)malloc(sizeof(struct sack)*n);
    for(int i=0;i<n;++i){
        fscanf(fp,"%d",&a[i].wt);
        fscanf(fp,"%d",&a[i].val);
    } 
    printf("\nEnter Capacity: ");
    scanf("%d",&curr_Capacity); 
    
    for(int i=0;i<n;++i){
        printf("%d %d",a[i].wt,a[i].val);
        printf("\n");
    } */

    printf("\n");
    
    sort(a,n);

    for(int i=0;i<n;++i)
    {
        printf("%d %d",a[i].wt,a[i].val);
        printf("\n");
    } 

    double res=0.0;
    for(int i=0;i<n;++i){
        if(a[i].wt<=curr_Capacity){
            res+=a[i].val;
            printf("\nWeight taken:%d ",a[i]);
            printf("\nIntermedaite Profit %d",i+1);
            printf(":");
            printf(" %.2lf",res);
            curr_Capacity-=a[i].wt;
            printf("\nRemaining Capacity: %d",curr_Capacity);
            printf("\n");
        }
        else{
            res+=a[i].val*((double)curr_Capacity/(double)a[i].wt);
            printf("\nWeight taken:%.2lf ",(double)curr_Capacity/(double)a[i].wt);
            printf("\nIntermedaite Profit %d",i+1);
            printf(":");
            printf(" %.2lf",res);
            printf("\nRemaining Capacity: 0");
            break;
        }
    }
    printf("\n\nFinal profit: %.2lf",res);

    return 0;
}