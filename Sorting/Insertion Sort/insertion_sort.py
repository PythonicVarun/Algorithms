# 
# Created by @PythonicVarun on 11-11-2024.
# 

from typing import List


def insertion_sort(arr: List, reverse: bool = False) -> None:
    """
    Sorts an array using the insertion sort algorithm with an option for reverse order.

    This function sorts an array of integers using the insertion sort algorithm. 
    If the `reverse` parameter is False, it sorts in ascending order. If `reverse` is True,
    it sorts in descending order.

    Time Complexity:
        - Best case: O(n), when the array is already sorted.
        - Average and Worst case: O(n^2), when the array is reverse sorted or unsorted.
    
    Space Complexity:
        - O(1), as the algorithm sorts in place.

    Parameters:
        arr (list): The array to be sorted.
        reverse (bool): If False, sorts in ascending order; if True, sorts in descending order.

    Returns:
        None: The function sorts the array in place.
    """
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1

        # Compare based on the reverse flag
        if not reverse:
            # Sort in ascending order
            while j >= 0 and arr[j] > key:
                arr[j + 1] = arr[j]
                j -= 1
        else:
            # Sort in descending order
            while j >= 0 and arr[j] < key:
                arr[j + 1] = arr[j]
                j -= 1
        
        arr[j + 1] = key

def main():
    """
    Main function to test the insertion sort algorithm with reverse functionality.

    This function initializes an array of integers, sorts it using insertion sort
    in both ascending and descending order, and prints the sorted arrays.

    Returns:
    None
    """
    arr = [64, 25, 12, 99, 22, 11]
    
    print("Original array:", arr)
    
    # Sort in ascending order
    insertion_sort(arr, reverse=False)
    print("Sorted array (ascending):", arr)
    
    # Sort in descending order
    insertion_sort(arr, reverse=True)
    print("Sorted array (descending):", arr)

if __name__ == "__main__":
    main()
