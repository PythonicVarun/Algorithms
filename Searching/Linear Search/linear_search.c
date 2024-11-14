//
// Created by @PythonicVarun on 11-11-2024.
//

#include <stdio.h>

/**
 * @brief Performs a linear search on an array to find a specified element.
 *
 * This function iterates through each element of the array and compares it with
 * the given element. If the element is found, the index of the element is returned.
 * Otherwise, the function returns -1.
 *
 * Time Complexity: O(n) - The algorithm may need to check every element in the array.
 * Space Complexity: O(1) - Uses constant space.
 * 
 * @param arr[] The array in which to search.
 * @param n The number of elements in the array.
 * @param element The element to search for.
 * @return int The index of the element if found, or -1 if not found.
 */
int linearSearch(int arr[], int n, int element) {
    for (int i = 0; i < n; i++)
        if (arr[i] == element)
            return i;
    return -1;
}

/**
 * @brief Main function to test the linear search algorithm.
 *
 * This function initializes an array, searches for a specified element using
 * linear search, and prints the result.
 *
 * @return int Program exit status.
 */
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int elementToFind = 22;

    printf("Searching for element %d in the array...\n", elementToFind);

    int index = linearSearch(arr, n, elementToFind);
    if (index != -1) {
        printf("Element %d found at index %d.\n", elementToFind, index);
    } else {
        printf("Element %d not found in the array.\n", elementToFind);
    }

    return 0;
}
