#include <stdio.h>
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i)
        printf("%d  ", array[i]);
    printf("\n");
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);
    for (int j = low; j <= high-1; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
            printArray(array,high+1);
        }
    }
    swap(&array[i + 1], &array[high]);
    printArray(array,high+1);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int main() {
    int n;
    printf("No. of elements in the array: ");
    scanf("%d",&n);
    
    int a[n];
    printf("Enter Array elements: ");
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    
    printf("\nGiven Array: ");
    printArray(a, n);
    printf("\n");
    printf("Sorting:\n");
    quickSort(a, 0, n - 1);
    
    printf("\nSorted array: ");
    printArray(a, n);
    return 0;
}