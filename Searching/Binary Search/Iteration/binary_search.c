//
// Created by @PythonicVarun on 11-11-2024.
//

#include <stdio.h>

/**
 * @brief Performs a binary search on a sorted array to find a specified element.
 *
 * This function uses an iterative approach to search for an element in a sorted array.
 * If the element is found, the index of the element is returned. If not, -1 is returned.
 *
 * Time Complexity: O(log n) - The search space is halved with each iteration.
 * Space Complexity: O(1) - Uses constant space regardless of the input size.
 * 
 * @param arr[] The sorted array in which to search.
 * @param element The element to search for.
 * @param n The number of elements in the array.
 * @return int The index of the element if found, or -1 if not found.
 */
int binarySearch(int arr[], int n, int element) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == element) {
            return mid;
        }
        if (arr[mid] > element) {
            high = mid - 1;  // Search the left half
        } else {
            low = mid + 1;   // Search the right half
        }
    }
    return -1;  // Element not found
}

/**
 * @brief Main function to test the iterative binary search algorithm.
 *
 * This function initializes a sorted array, searches for a specified element using
 * binary search, and prints the result.
 *
 * @return int Program exit status.
 */
int main() {
    int arr[] = {11, 22, 25, 64, 78};
    int n = sizeof(arr) / sizeof(arr[0]);
    int elementToFind = 64;

    printf("Searching for element %d in the sorted array...\n", elementToFind);

    int index = binarySearch(arr, n, elementToFind);
    if (index != -1) {
        printf("Element %d found at index %d.\n", elementToFind, index);
    } else {
        printf("Element %d not found in the array.\n", elementToFind);
    }

    return 0;
}
