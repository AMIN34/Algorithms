#include <stdio.h>

void printMergeSort(int arr[], int left, int mid ,int right)
{
    printf("[");
    for (int i = left; i < mid; ++i)
    {
        if (i != 0)
            printf(", ");
        printf("%d", arr[i]);
    }
    printf("], [");

    for (int i = mid; i < right; ++i)
    {
        if (i != 0)
            printf(", ");
        printf("%d", arr[i]);
    }
    printf("]\n");

}
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void merge(int arr[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], M[n2];
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m); //printArray(arr, r);
    mergeSort(arr, m + 1, r); //printArray(arr, r);
    merge(arr, l, m, r); // printArray(arr, r);
    printMergeSort(arr,l,m,r);

  }
}

int main() {
    int size;
	int arr[size];
	
	printf("Enter the size of the array :- ");
	scanf("%d",&size);
	printf("Enter Array :- ");
	for(int i=0;i<size;++i)
		scanf("%d",&arr[i]);

  mergeSort(arr, 0, size - 1);

  printf("Sorted array: \n");
  printArray(arr, size);
}