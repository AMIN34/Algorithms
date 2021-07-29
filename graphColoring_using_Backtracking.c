#include<stdio.h>
void gc()
{
	int n;
    printf("Please enter the number of nodes:");
    scanf("%d",&n);
    printf("Please enter the adjacency matrix:\n");
	for(int i=0;i<n;i++)
	printf("%3d",i+1);
	printf("\n");
	int a[n][n];
	for(int i=0;i<n;i++)        //The adjacency matrix stores graph information 
	{
		printf("%-2d",i+1);
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	getchar();
	}
	int m;
	printf("Please enter the number of colors:");
	scanf("%d",&m);
	int result[n];                   //Store the coloring of each vertex 
	for(int i=0;i<n;i++)
	result[i]=0;
	result[0]=1;               
	int k=1;
	while(k>-1)
	{
		result[k]++;
		while(result[k]<=m)
		{
			int flag=0;
			for(int j=0;j<k;j++)         //Traverse the colored vertices and determine whether the constraints are met 
	    {
	    	if(a[k][j]==1 && result[k]==result[j])
	    	flag=1;
		}
		if(flag==0)
		break;
		else
		result[k]++;
		}
	    if(result[k]<=m)
	    {
	    	if(k==n-1)                   //The last vertex is successfully colored and jumps out of the loop 
	    	break;
	    	else 
	    	k++;                         //Continue to color the vertices 
		}
		else
		{
		result[k]=0;
		 k--;	                         //The vertex does not meet the constraints of coloring, backtracking 
		}
	   
	}
	if(k==-1)
	printf("No solution");
	else
	{ 
        printf("One solution to the problem of graph coloring is:\n");
		for(int i=0;i<n;i++)
		printf("Node %d color number: %d\n",i+1,result[i]);
	 } 
 } 
void main(){
 	gc();
 }
