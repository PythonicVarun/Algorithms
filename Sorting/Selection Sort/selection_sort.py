# 
# Created by @PythonicVarun on 11-11-2024.
# 

from typing import List


def selection_sort(arr: List, reverse: bool = False) -> None:
    """
    Sorts an array using the selection sort algorithm with an option for reverse order.

    This function sorts an array of integers in ascending or descending order using 
    the selection sort algorithm. If the `reverse` parameter is False, it sorts in 
    ascending order. If `reverse` is True, it sorts in descending order.

    Time Complexity:
        - O(n^2): The selection sort algorithm always makes n^2 comparisons, regardless of the initial order of elements.
          The inner loop runs n-i times for each i, leading to n(n-1)/2 comparisons in total.
    
    Space Complexity:
        - O(1): Selection sort is an in-place sorting algorithm, meaning it requires only a constant amount of additional memory.

    Parameters:
        arr (list): The array to be sorted.
        reverse (bool): If False, sorts in ascending order; if True, sorts in descending order.

    Returns:
        None: The function sorts the array in place.
    """
    n = len(arr)
    for i in range(n):
        min_or_max = i
        for j in range(i + 1, n):
            if (not reverse and arr[min_or_max] > arr[j]) or (reverse and arr[min_or_max] < arr[j]):
                min_or_max = j
        arr[i], arr[min_or_max] = arr[min_or_max], arr[i]

def main():
    """
    Main function to test the selection sort algorithm with reverse functionality.

    This function initializes an array of integers, sorts it using selection sort
    in both ascending and descending order, and prints the sorted arrays.

    Returns:
        None
    """
    arr = [64, 25, 12, 99, 22, 11]
    
    print("Original array:", arr)
    
    # Sort in ascending order
    selection_sort(arr, reverse=False)
    print("Sorted array (ascending):", arr)
    
    # Sort in descending order
    selection_sort(arr, reverse=True)
    print("Sorted array (descending):", arr)

if __name__ == "__main__":
    main()
