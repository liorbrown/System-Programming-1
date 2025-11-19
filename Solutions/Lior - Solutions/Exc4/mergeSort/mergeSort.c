#include "mergeSort.h"
#include <stdio.h>

/**
 * @brief Merges two sorted subarrays into one sorted array using auxiliary buffer
 * 
 * @param left Pointer to the start of the left subarray
 * @param mid Pointer to the end of the left subarray
 * @param right Pointer to the end of the right subarray
 * @param aux Pointer to auxiliary array for temporary storage
 */
void merge(int *left, int *mid, int *right, int *aux) 
{
    if (!(left && mid && right && aux))
        return;

    int *leftPtr = left;      /* Pointer to current element in left subarray */
    int *rightPtr = mid + 1;  /* Pointer to current element in right subarray */
    int *auxPtr = aux;        /* Pointer to current position in auxiliary array */
    
    /* Merge the two subarrays into aux using pointer comparison */
    while (leftPtr <= mid && rightPtr <= right)
        if (*leftPtr <= *rightPtr)
            *auxPtr++ = *leftPtr++;
        else
            *auxPtr++ = *rightPtr++;
        
    /* Copy remaining elements of left subarray, if any */
    while (leftPtr <= mid)
        *auxPtr++ = *leftPtr++;
    
    /* Copy remaining elements of right subarray, if any */
    while (rightPtr <= right)
        *auxPtr++ = *rightPtr++;
    
    /* Copy merged elements back to original array using pointers */
    auxPtr = aux;
    for (int *ptr = left; ptr <= right; ptr++)
        *ptr = *auxPtr++;
}

/**
 * @brief Recursive helper function for merge sort
 * 
 * @param left Pointer to the start of the subarray to sort
 * @param right Pointer to the end of the subarray to sort
 * @param aux Pointer to auxiliary array for temporary storage
 */
void mergeSortHelper(int *left, int *right, int *aux) 
{
    if (!(left  && right && aux && right > left))
        return;

    /* Calculate mid pointer using pointer arithmetic */
    int *mid = left + (right - left) / 2;
    
    /* Sort first and second halves */
    mergeSortHelper(left, mid, aux);
    mergeSortHelper(mid + 1, right, aux);
    
    /* Merge the sorted halves */
    merge(left, mid, right, aux);    
}

void mergeSort(int *arr) {
    if (!arr)
        return;
    
    /* Allocate auxiliary array with fixed size */
    int aux[ARRAY_SIZE];
    
    /* Call helper with pointers to first and last elements */
    mergeSortHelper(arr, arr + ARRAY_SIZE - 1, aux);
}
