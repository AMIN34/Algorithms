#include<stdio.h>
#include<stdlib.h>

int n;
int visited[100]={0};

typedef struct node
{
    int data;
    struct node *link;
}node;

struct node *front=NULL;
struct node *rear=NULL;

int isEmpty()
{
    if(front==NULL && rear==NULL)
        return 1;
    else
        return 0;
        
}
void enqueue(int x)
{
    struct node* newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->link=NULL;
    if(isEmpty())
        front=rear=newnode;
    else
    {
        rear->link=newnode;
        rear=newnode;    
    }
}

void dequeue()
{
    struct node* temp;
    if(isEmpty())
        printf("\nGraph is empty");
    else if(front==rear)
    {
        temp=front;
        front=rear=NULL;
        free(temp);
    }
    else
    {
        temp=front;
        front=front->link;
        free(temp);
    }
}

int peek()
{
    if(isEmpty());
    else
        return(front->data);
}

void BFS(int graph[][n])
{
    if(isEmpty())
        return;
    int visitedNode=peek();
    printf("%d ",peek());
    dequeue();
    for(int i=0;i<n;++i)
    {
        if(graph[visitedNode][i]==1 && (!visited[i]))
        {
            enqueue(i);
            visited[i]=1;
        }
    }
    BFS(graph);
    
}

int main()
{
    FILE *fp;
    fp=fopen("bfs.txt","r");
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
    printf("\nGiven Matrix:\n");
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
    printf("BFS Traversal: ");
    enqueue(src);
    visited[src]=1;
    BFS(graph);

    return 0;
}
