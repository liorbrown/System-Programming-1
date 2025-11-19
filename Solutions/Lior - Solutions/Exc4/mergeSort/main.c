#include "mergeSort.h"
#include <stdio.h>

/**
 * @brief Prints an array to stdout (testing helper)
 * 
 * @param arr Pointer to the array to print (ARRAY_SIZE elements)
 */
void printArray(int *arr) 
{
    if (!arr)
        return;

    int *end = arr-- + ARRAY_SIZE - 1;  /* Pointer to  last element */
    
    putchar('[');

    while(++arr <= end)
        printf(" %d %c ", *arr, arr == end ? ']' : ',');
    
    putchar('\n');
}

int main() {
    /* Test case 1: Regular array */
    int arr1[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50};
    
    printf("Original array: ");
    printArray(arr1);
    
    mergeSort(arr1);
    
    printf("Sorted array:   ");
    printArray(arr1);
    printf("\n");
    
    /* Test case 2: Already sorted array */
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    printf("Original array: ");
    printArray(arr2);
    
    mergeSort(arr2);
    
    printf("Sorted array:   ");
    printArray(arr2);
    printf("\n");
    
    /* Test case 3: Reverse sorted array */
    int arr3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    printf("Original array: ");
    printArray(arr3);
    
    mergeSort(arr3);
    
    printf("Sorted array:   ");
    printArray(arr3);
    printf("\n");
    
    /* Test case 4: Array with duplicates */
    int arr4[] = {5, 2, 8, 2, 9, 1, 5, 5, 3, 8};
    
    printf("Original array: ");
    printArray(arr4);
    
    mergeSort(arr4);
    
    printf("Sorted array:   ");
    printArray(arr4);
    
    return 0;
}
