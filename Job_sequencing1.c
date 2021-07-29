#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char id;
    int deadline;
    int profit;

}Job;

int compareJob(const Job *a, const Job *b){
    return b->profit - a->profit;
}



void bestJob(Job jobs[],int sizeOfJobs){
    char jobsToDo[5]= {'\0'};

    for(int i=0, k=0; i<sizeOfJobs; i++){
        k = jobs[i].deadline-1;
        while(jobsToDo[k] != '\0' && k >= 0){
            k--;
        }

        if(k != -1)
            jobsToDo[k]= jobs[i].id;
    }


    printf("\nBest order and jobs to do is: ");
    int idx=0;
    while(jobsToDo[idx] != '\0'){
        printf("%c ",jobsToDo[idx]);
        idx++;
    }
}

void display(Job jobs[], int n){
    printf("Job Id:     \t");
    for(int i=0; i<n; i++){
        printf("%c \t",jobs[i].id);
    }
    printf("\n");

    printf("Job Deadline: \t");
    for(int i=0; i<n; i++){
        printf("%d \t",jobs[i].deadline);
    }
    printf("\n");

    printf("Job Profit: \t");
    for(int i=0; i<n; i++){
         printf("%d \t",jobs[i].profit);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("\nEnter no. of elements : ");
    scanf("%d",&n);
    Job jobs[n];
    for(int i=0;i<n;i++){
        printf("\nEnter id:");
        scanf(" %c",&jobs[i].id);
        printf("\nEnter deadline:");
        scanf("%d",&jobs[i].deadline);
        printf("\nEnter profit:");
        scanf("%d",&jobs[i].profit);
    }
    //Job jobs[]=  {{'w', 1, 19}, {'v', 2, 100}, {'x', 2, 27},{'y', 1, 25}, {'z', 3, 15}};
    display(jobs,n);
    qsort(jobs,n,sizeof(jobs[0]),compareJob);
    bestJob(jobs,n);
    return 0;
}