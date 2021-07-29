#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i)
    printf("%d  ", array[i]);
  printf("\n");
}

void selectionSort(int array[], int size){
    int min_idx;
    for (int i = 0; i < size - 1; i++){
      min_idx = i;
      for (int j = i + 1; j < size; j++)
        if (array[j] < array[min_idx])
          min_idx = j;
      swap(&array[min_idx], &array[i]);
      printArray(array,size);
    }
}

int main(){
  int n, *arr;
  printf("Enter the size of array : ");
  scanf("%d",&n);
	arr = (int *)malloc(n * sizeof(int));
  printf("Enter the array elements : ");
  for (int i = 0; i < n; i++)
    scanf("%d",&arr[i]);
  printf("Initial array is : ");
  printArray(arr,n);
  printf("Sorting:\n");
  selectionSort(arr, n);
  printf("Sorted array : \n");
  printArray(arr, n);
  return 0;
}