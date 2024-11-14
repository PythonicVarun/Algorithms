# 
# Created by @PythonicVarun on 11-11-2024.
# 

from typing import List


def bubble_sort(arr: List, reverse: bool = False) -> None:
    """
    Sorts an array using the bubble sort algorithm with an option for reverse order.

    This function sorts an array of integers in ascending or descending order
    based on the value of the `reverse` parameter. If `reverse` is False, it sorts
    in ascending order. If `reverse` is True, it sorts in descending order.

    Time Complexity:
        - Worst and Average Case: O(n^2) when the array is unsorted.
        - Best Case: O(n) when the array is already sorted (due to the early exit optimization).

    Space Complexity: O(1), as the sorting is done in-place.

    Parameters:
        arr (list): The array to be sorted.
        reverse (bool): If False, sorts in ascending order; if True, sorts in descending order.

    Returns:
        None: The function sorts the array in place.
    """
    n = len(arr)
    for i in range(n):
        flag = False
        for j in range(n - i - 1):
            if (not reverse and arr[j] > arr[j + 1]) or (reverse and arr[j] < arr[j + 1]):
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                flag = True
        if flag is True:
            return  # If no elements were swapped, the array is already sorted

def main():
    """
    Main function to test the bubble sort algorithm with reverse functionality.

    This function initializes an array of integers, sorts it using bubble sort
    in both ascending and descending order, and prints the sorted arrays.

    Returns:
        None
    """
    arr = [64, 25, 12, 99, 22, 11]
    
    print("Original array:", arr)
    
    # Sort in ascending order
    bubble_sort(arr, reverse=False)
    print("Sorted array (ascending):", arr)
    
    # Sort in descending order
    bubble_sort(arr, reverse=True)
    print("Sorted array (descending):", arr)

if __name__ == "__main__":
    main()
