#include<stdio.h>
#include<stdlib.h>

int ne=1;

void printGraph(int n,int dist[][n])
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(dist[i][j]==9999)
                printf("%7s","INF");
            else
                printf("%7d",dist[i][j]);
        }
        printf("\n");
    }
    printf("\nShortest path:\n");
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j){
            if(dist[i][j]==9999)
                printf("%d) edge (%d,%d) = %s\n",ne++,i,j,"INF");
            else
                printf("%d) edge (%d,%d) = %d\n",ne++,i,j,dist[i][j]);
        }
        printf("\n");
    }
}
int floydWarshal(int n,int graph[][n])
{
    int i,j,k;
    int dist[n][n];
    for( i=0;i<n;++i)
        for(j=0;j<n;++j)
            dist[i][j]=graph[i][j];

    for(k=0;k<n;++k)
        for(i=0;i<n;++i)
            for(j=0;j<n;++j)
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
    
    for(int i=0;i<n;++i)
    {
        if(dist[i][i]<0)
        {
            printf("Negative edge cycle detected!!!");
            exit(1);
        }    
    }  

    printf("\nShortest Length Matrix:\n");
    printGraph(n,dist);
    printf("\n");
}
int main()
{
    FILE *fp;
    fp=fopen("fs3.txt","r");
    if(fp==NULL)
    {
        printf("\nError to open the file\n");
        exit(1);
    }
    int n;
    fscanf(fp,"%d",&n);
    printf("Number of vertices:%d ",n);

    int graph[n][n];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            fscanf(fp,"%d",&graph[i][j]);
    
    fclose(fp);
    printf("\n");
    printf("\nGiven adjacent matrix:\n");
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j){
            if(graph[i][j]==9999)
                printf("%7s","INF");
            else
                printf("%7d",graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    floydWarshal(n,graph);
    return 0;
}