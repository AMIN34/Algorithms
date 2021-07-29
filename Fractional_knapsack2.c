#include<stdio.h>

typedef struct Fractional_Knapsack
{
	int value;
	int weight;
	int vw;
} Knap;

typedef struct materials_taken
{
	double val;
	double weight;
} Materials;

double fractional_knapsack(int w,Knap a[],int n)
{	
	int i,j=0;
	Materials o_vector[n];
	double v=0.0;
	for(i=0;i<n;i++)
	{
		if(w>0&&a[i].weight<=w)
		{
			o_vector[j].val=(double)a[i].value;
			o_vector[j].weight=(double)a[i].weight;
			j++;
			w=w-a[i].weight;
			v+=a[i].value;
		}
		else
		{
			break;
		}
	}
	if(w>0)
	{
		o_vector[j].val=(double)a[i].value;
		o_vector[j].weight=(double)w/(double)a[i].weight;
		v=v+(a[i].value*((double)w/(double)a[i].weight));
	}
	printf("\n\nThe output vector is : \n\n");
	for(i=0;i<=j;i++)
	{
		printf("Object[%d] : ",i+1);
		printf("\t");
		printf("Value : %.2f",o_vector[i].val);
		printf("\t");
		printf("Weights : %.2f",o_vector[i].weight);
		printf("\n");
	}
	return v;
}

void sort_objects(Knap a[],int n)
{
	int i,j;
	Knap t;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(a[j+1].vw>a[j].vw)
			{
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
}

int main()
{
	int w,n,i;
	double optimal_value;
	printf("Enter the capacity of knapsack : ");
	scanf("%d",&w);
	printf("\nEnter the no of objects : ");
	scanf("%d",&n);
	Knap obj[n];
	for(i=0;i<n;i++)
	{
		printf("\nEnter the value and weight : ");
		scanf("%d,%d",&obj[i].value,&obj[i].weight);
		obj[i].vw=obj[i].value/obj[i].weight;
	}
	sort_objects(obj,n);
	printf("\nThe values and weights after arranging them in decreasing order of v/w ratio : ");
	for(i=0;i<n;i++)
	{
		printf("%d-%d",obj[i].value,obj[i].weight);
		if(i!=n-1)
		{
			printf(" > ");	
		}
	}
	optimal_value=fractional_knapsack(w,obj,n);
	printf("\nThe optimal value is %.0lf",optimal_value);
}

