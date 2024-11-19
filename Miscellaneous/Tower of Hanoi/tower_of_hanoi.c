//
// Created by @PythonicVarun on 19-11-2024.
//

#include <stdio.h>

/**
 * @brief Solves the Tower of Hanoi puzzle.
 *
 * This function uses recursion to solve the Tower of Hanoi puzzle for `n` disks.
 * The goal is to move all the disks from the source peg to the destination peg using
 * an auxiliary peg, following these rules:
 * 1. Only one disk can be moved at a time.
 * 2. A disk can only be moved if it is the top disk on a peg.
 * 3. No disk may be placed on top of a smaller disk.
 *
 * @note Time Complexity: O(2^n)
 *     The algorithm's time complexity is exponential, as each call results in two more recursive calls
 *     until the base case (n = 1) is reached. Specifically, there are 2^n - 1 moves for `n` disks.
 *
 * @note Space Complexity: O(n) - The space complexity is linear because the maximum depth of the recursion tree is `n`.
 *
 * @param n The number of disks to move.
 * @param source The peg from which disks are moved initially.
 * @param dest The peg to which disks are moved.
 * @param aux The auxiliary peg used in the process.
 */
void towerOfHanoi(int n, char source, char dest, char aux) {
    if (n == 1) {
        printf("Move disk 1: %c -> %c\n", source, dest);
        return;
    }
    // Move n-1 disks from source to auxiliary peg
    towerOfHanoi(n - 1, source, aux, dest);
    // Move the nth disk from source to destination peg
    printf("Move disk %d: %c -> %c\n", n, source, dest);
    // Move n-1 disks from auxiliary peg to destination peg
    towerOfHanoi(n - 1, aux, dest, source);
}

/**
 * @brief Main function to solve the Tower of Hanoi puzzle.
 *
 * This function prompts the user to enter the number of disks and then prints the
 * sequence of moves required to solve the Tower of Hanoi puzzle.
 *
 * @return int Program exit status.
 */
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Steps to solve the Tower of Hanoi for %d disks:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
