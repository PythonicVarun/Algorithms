//
// Created by @PythonicVarun on 11-11-2024.
//

#include <stdio.h>

/**
 * @brief Swaps the values of two integers.
 *
 * This function takes pointers to two integers and swaps their values.
 *
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Sorts an array using the selection sort algorithm with an option for reverse order.
 *
 * This function sorts an array of integers in ascending or descending order using the
 * selection sort algorithm. If the `reverse` parameter is 0, it sorts in ascending order.
 * If `reverse` is 1, it sorts in descending order.
 *
 * Time Complexity:
 * - O(n^2) in all cases (best, average, and worst), because the selection sort algorithm
 *   always makes n^2 comparisons, regardless of the initial order of elements.
 * 
 * Space Complexity: O(1), as the sorting is done in-place.
 *
 * @param arr[] The array to be sorted.
 * @param n The number of elements in the array.
 * @param reverse If 0, sorts in ascending order; if 1, sorts in descending order.
 */
void selectionSort(int arr[], int n, int reverse) {
    for (int i = 0; i < n; i++) {
        int minOrMax = i;
        for (int j = i + 1; j < n; j++) {
            if ((reverse == 0 && arr[minOrMax] > arr[j]) || (reverse == 1 && arr[minOrMax] < arr[j])) {
                minOrMax = j;
            }
        }
        swap(&arr[minOrMax], &arr[i]);
    }
}

/**
 * @brief Main function to test the selection sort algorithm with reverse functionality.
 *
 * This function initializes an array of integers, sorts it using
 * selection sort in both ascending and descending order, and prints the sorted arrays.
 *
 * @return int Program exit status.
 */
int main() {
    int arr[] = {64, 25, 12, 99, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort in ascending order
    selectionSort(arr, n, 0);
    printf("Sorted array (ascending): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort in descending order
    selectionSort(arr, n, 1);
    printf("Sorted array (descending): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
