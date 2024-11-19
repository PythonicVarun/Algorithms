# 
# Created by @PythonicVarun on 14-11-2024.
# 

def tower_of_hanoi(n: int, source: str, dest: str, aux: str) -> None:
    """
    Solves the Tower of Hanoi puzzle using recursion.

    This function prints the sequence of moves to solve the Tower of Hanoi puzzle
    for `n` disks. The goal is to move all the disks from the source peg to the 
    destination peg using an auxiliary peg, following these rules:
    1. Only one disk can be moved at a time.
    2. A disk can only be moved if it is the top disk on a peg.
    3. No disk may be placed on top of a smaller disk.

    Time Complexity:
        O(2^n) - The algorithm's time complexity is exponential because each call 
        results in two more recursive calls until the base case (n = 1) is reached.
        Specifically, there are 2^n - 1 moves for `n` disks.

    Space Complexity:
        O(n) - The space complexity is linear as the maximum depth of the recursion 
        tree is `n`.

    Parameters:
        n (int): The number of disks to move.
        source (str): The peg from which disks are moved initially.
        dest (str): The peg to which disks are moved.
        aux (str): The auxiliary peg used during the process.

    Returns:
        None: This function does not return anything; it prints the steps to solve the puzzle.
    """
    if n == 1:
        print(f"Move disk {n}: {source} -> {dest}")
        return

    # Move n-1 disks from source to auxiliary peg
    tower_of_hanoi(n - 1, source, aux, dest)
    # Move the nth disk from source to destination peg
    print(f"Move disk {n}: {source} -> {dest}")
    # Move n-1 disks from auxiliary peg to destination peg
    tower_of_hanoi(n - 1, aux, dest, source)

def main() -> None:
    """
    Main function to solve the Tower of Hanoi puzzle.

    This function prompts the user to enter the number of disks and then prints 
    the sequence of moves required to solve the Tower of Hanoi puzzle.
    """
    n = int(input("Enter number of disks: "))
    print(f"Steps to solve the Tower of Hanoi for {n} disks:\n")

    tower_of_hanoi(n, "A", "B", "C")

if __name__ == "__main__":
    main()
