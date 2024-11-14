//
// Created by @PythonicVarun on 11-11-2024.
//

#include <stdio.h>

/**
 * @brief Sorts an array using the insertion sort algorithm with an option for reverse order.
 *
 * This function sorts an array of integers using the insertion sort algorithm.
 * If the `reverse` parameter is 0, it sorts in ascending order. If `reverse` is 1,
 * it sorts in descending order.
 *
 * Time Complexity:
 * - Worst and Average Case: O(n^2), where n is the number of elements in the array.
 * - Best Case: O(n), when the array is already sorted.
 *
 * Space Complexity: O(1), as the sorting is done in-place.
 * 
 * @param arr[] The array to be sorted.
 * @param n The number of elements in the array.
 * @param reverse If 0, sorts in ascending order; if 1, sorts in descending order.
 */
void insertionSort(int arr[], int n, int reverse) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Compare based on the reverse flag
        if (reverse == 0) {
            // Sort in ascending order
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
        } else {
            // Sort in descending order
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        arr[j + 1] = key;
    }
}

/**
 * @brief Main function to test the insertion sort algorithm with reverse functionality.
 *
 * This function initializes an array of integers, sorts it using
 * insertion sort in both ascending and descending order, and prints the sorted arrays.
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
    insertionSort(arr, n, 0);
    printf("Sorted array (ascending): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort in descending order
    insertionSort(arr, n, 1);
    printf("Sorted array (descending): ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
