# 
# Created by @PythonicVarun on 14-11-2024.
# 

from typing import List, Any


def linear_search(arr: List, element: Any) -> int:
    """
    Performs a linear search on an array to find a specified element.

    This function iterates through each element of the array and compares it with
    the given element. If the element is found, the index of the element is returned.
    Otherwise, the function returns -1.

    Time Complexity: O(n) - The algorithm may need to check every element in the array.
    Space Complexity: O(1) - Uses constant space.

    Parameters:
        arr (list): The array in which to search.
        element (any): The element to search for.

    Returns:
        int: The index of the element if found, or -1 if not found.
    """
    for i in range(len(arr)):
        if arr[i] == element:
            return i
    return -1

def main():
    """
    Main function to test the linear search algorithm.

    This function initializes an array, searches for a specified element using
    linear search, and prints the result.

    Returns:
    None
    """
    arr = [64, 25, 12, 22, 11]
    element_to_find = 22

    print(f"Searching for element {element_to_find} in the array...")

    index = linear_search(arr, element_to_find)
    if index != -1:
        print(f"Element {element_to_find} found at index {index}.")
    else:
        print(f"Element {element_to_find} not found in the array.")

if __name__ == "__main__":
    main()
