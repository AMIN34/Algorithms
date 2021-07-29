#include<stdio.h>
#include<stdlib.h>

int visited[100]={0};
int n;

typedef struct node
{
    int data;
    struct node *link;
}node;

struct node *top=NULL;

int isEmpty()
{
    if(top==NULL)
        return 1;
    else 
        return 0;
}
void push(int x)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=top;
    top=newnode;
}

void pop()
{
    struct node *temp;
    if(top==NULL)
        printf("\nGraph is empty");
    else
    {
        temp=top;
        top=top->link;
        free(temp);
    }
}

int peek()
{
    if(isEmpty());
    else
        return (top->data);
}

void DFS(int graph[][n],int src)
{
    push(src);
    visited[src]=1;
    while(!isEmpty())
    {
        int visitedNode=peek();
        printf("%d ",peek());
        pop();
        for(int i=0;i<n;++i)
        {
            if(graph[visitedNode][i]==1 && (!visited[i]))
            {
                push(i);
                visited[i]=1;
            }
        }
    }
    return;    
}

int main()
{
    FILE *fp;
    fp=fopen("dfs.txt","r");
    if(fp==NULL)
    {
        printf("\nError to open the file\n");
        exit(1);
    }
    fscanf(fp,"%d",&n);
    int graph[n][n];
    int i,j;
    for(i=0;i<n;++i)
        for(j=0;j<n;++j)
            fscanf(fp,"%d",&graph[i][j]);
    printf("\nGiven matrix:\n");
    for(i=0;i<n;++i)
    {
        for(j=0;j<n;++j)
            printf("%3d",graph[i][j]);
        printf("\n");
    }
    fclose(fp);

    int src;
    printf("Enter the source vertex: ");
    scanf("%d",&src);
    
    if(src>=n){    
        printf("Source is out of bound!!!");
        exit(1);
    }

    printf("DFS Traversal: ");
    
    DFS(graph,src);

    return 0;
}