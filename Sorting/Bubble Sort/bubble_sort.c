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
 * @brief Sorts an array using the bubble sort algorithm with an option for reverse order.
 *
 * This function sorts an array of integers in ascending or descending order using the
 * bubble sort algorithm. If the `reverse` parameter is 0, it sorts in ascending order.
 * If `reverse` is 1, it sorts in descending order.
 *
 * @note Time Complexity:
 *     - Worst and Average Case: O(n^2) when the array is unsorted.
 *     - Best Case: O(n) when the array is already sorted (due to early exit optimization).
 *
 * @note Space Complexity: O(1), since the sorting is done in-place.
 * 
 * @param arr[] The array to be sorted.
 * @param n The number of elements in the array.
 * @param reverse If 0, sorts in ascending order; if 1, sorts in descending order.
 */
void bubbleSort(int arr[], int n, int reverse) {
    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if ((reverse == 0 && arr[j] > arr[j + 1]) || (reverse == 1 && arr[j] < arr[j + 1])) {
                flag = 1;
                swap(&arr[j], &arr[j + 1]);
            }
        }
        if (flag == 0) return;  // If no elements were swapped, the array is sorted
    }
}

/**
 * @brief Main function to test the bubble sort algorithm with reverse functionality.
 *
 * This function initializes an array of integers, sorts it using
 * bubble sort in both ascending and descending order, and prints the sorted arrays.
 *
 * @return int Program exit status.
 */
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort in ascending order
    bubbleSort(arr, n, 0);
    printf("Sorted array (ascending): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort in descending order
    bubbleSort(arr, n, 1);
    printf("Sorted array (descending): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
