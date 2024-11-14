# 
# Created by @PythonicVarun on 14-11-2024.
# 

from typing import List, Optional


def binary_search(arr: List[int], element: int, low: Optional[int] = 0, high: Optional[int] = None) -> 0:
    """
    Performs a binary search on a sorted array to find a specified element.

    This function uses a recursive approach to search for an element in a sorted array.
    If the element is found, the index of the element is returned. If not, -1 is returned.

    Time Complexity: O(log n) - The search space is halved with each recursive call.
    Space Complexity: O(1) - Uses constant space regardless of the input size.

    Parameters:
        arr (list): The sorted array in which to search.
        element (int): The element to search for.
        low (optional int): The starting index of the subarray to search.
        high (optional int): The ending index of the subarray to search.

    Returns:
        int: The index of the element if found, or -1 if not found.
    """
    if high is None:
        high = len(arr) - 1

    while low <= high:
        mid = low + (high - low) // 2
        if arr[mid] == element:
            return mid
        elif arr[mid] > element:
            high = mid - 1  # Search the left half
        else:
            low = mid + 1  # Search the left half
    return -1

def main():
    """
    Main function to test the binary search algorithm.

    This function initializes a sorted array, searches for a specified element using
    binary search, and prints the result.

    Returns:
    None
    """
    arr = [11, 22, 25, 64, 78]
    element_to_find = 64

    print(f"Searching for element {element_to_find} in the sorted array...")

    index = binary_search(arr, element_to_find)
    if index != -1:
        print(f"Element {element_to_find} found at index {index}.")
    else:
        print(f"Element {element_to_find} not found in the array.")

if __name__ == "__main__":
    main()
