#include<stdio.h>
#include<stdlib.h>
int a,b,u,v,n,i,j,ne=1;
int visited[10]= {
	0
}
,min,mincost=0,cost[10][10];
void main() {
	FILE *f;
    // f = fopen("g3.txt", "r");
	f = fopen("g4.txt", "r");
    if (f == NULL){
        printf("Error opening the file");
        exit(-1);
    }
   	printf("Enter the no. of vertices - ");
    fscanf(f,"%d",&n);
    printf(" %d\n",n);
	printf("\nEnter the Weights adjacency matrix:\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			fscanf(f," %d",&cost[i][j]);
			printf(" %d\t",cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
		printf("\n");
	}
	visited[1]=1;
	printf("\n");
	while(ne<n) {
		for (i=1,min=999;i<=n;i++)
		   for (j=1;j<=n;j++)
		    if(cost[i][j]<min)
		     if(visited[i]!=0) {
			min=cost[i][j];
			a=u=i;
			b=v=j;
		}
		if(visited[u]==0 || visited[v]==0) {
			printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
			mincost+=min;
			visited[b]=1;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n Minimun cost=%d",mincost);
}