#include <stdio.h>
#define MAX 100

typedef struct Job {
    char id[5];
    int deadline;
    int profit;
} Job;

int minValue(int x, int y) {
    if(x < y) return x;
    return y;
}

void jobSequencingWithDeadline(Job jobs[], int n) {

    int i, j, k, maxprofit;

    //free time slots
    int timeslot[MAX];

    //filled time slots
    int filledTimeSlot = 0;

    //find max deadline value
    int dmax = 0;
    for(i = 0; i < n; i++) 
        if(jobs[i].deadline > dmax)
            dmax = jobs[i].deadline;
    
    //free time slots initially set to -1 [-1 denotes EMPTY]
    for(i = 1; i <= dmax; i++)
        timeslot[i] = -1;

    printf("dmax: %d\n", dmax);

    for(i = 1; i <= n; i++) {
        k = minValue(dmax, jobs[i - 1].deadline);
        while(k >= 1) {
            if(timeslot[k] == -1) {
                timeslot[k] = i-1;
                filledTimeSlot++;
                break;
            }
        k--;
        }

        //if all time slots are filled then stop
        if(filledTimeSlot == dmax)
            break;
    }

    //required jobs
    printf("\nRequired Jobs: ");
    for(i = 1; i <= dmax; i++) {
        printf("%s", jobs[timeslot[i]].id);

        if(i < dmax)
            printf(" --> ");
        
    }

    //required profit
    maxprofit = 0;
    for(i = 1; i <= dmax; i++)
        maxprofit += jobs[timeslot[i]].profit;

    printf("\nMax Profit: %d\n", maxprofit);
}


int main() {
    int i, j;

    /* int n = 4;
    //jobs with deadline and profit
    Job jobs[4] = {
        {"j1",2,100},
        {"j2",1,10},
        {"j3",2,15},
        {"j4",1,27},
    }; */

    /* //number of jobs
    int n = 3;
    //jobs with deadline and profit
    Job jobs[3] = {
        {"j1",2,10},
        {"j2",2,50},
        {"j3",1,25},
    }; */

    int n;
    printf("\nEnter no. of elements : ");
    scanf("%d",&n);
    Job jobs[n];
    for(int i=0;i<n;i++){
        printf("\nEnter id:");
        scanf("%s",jobs[i].id);
        printf("\nEnter deadline:");
        scanf("%d",&jobs[i].deadline);
        printf("\nEnter profit:");
        scanf("%d",&jobs[i].profit);
    }

    //temp
    Job temp;

    //sort the jobs profit wise in descending order
    for(i = 1; i < n; i++) {
        for(j = 0; j < n - i; j++) {
            if(jobs[j+1].profit > jobs[j].profit) {
                temp = jobs[j+1];
                jobs[j+1] = jobs[j];
                jobs[j] = temp;
            }
        }
    }

    printf("%10s %10s %10s\n", "Job", "Deadline", "Profit");
    for(i = 0; i < n; i++)
        printf("%10s %10i %10i\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);

    jobSequencingWithDeadline(jobs, n);
}