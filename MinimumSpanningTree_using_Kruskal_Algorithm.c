#include<stdio.h>
#include<stdlib.h>
int i,j,k,a,b,u,v,n,ne=1;
int min,mincost=0,cost[20][20],parent[20];

int find(int i){
	while(parent[i])
		i=parent[i];
	return i;
}
int uni(int i,int j){
	if(i!=j){
		parent[j]=i;
		return 1;
	}
	return 0;
}
void main()
{
	FILE *f;
    // f = fopen("g3.txt", "r");
	f = fopen("g4.txt", "r");
    if (f == NULL){
        printf("Error opening the file");
        exit(-1);
    }
   	printf("No. of vertices: ");
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
	printf("The edges of Minimum Cost Spanning Tree are: \n");
	while(ne < n){
		for(i=1,min=999;i<=n;i++){
			for(j=1;j <= n;j++){
				if(cost[i][j] < min){
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v)){
			printf("%d) edge (%d,%d) = %d\n",ne++,a,b,min);
			mincost +=min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n\tMinimum cost = %d\n",mincost);
}

