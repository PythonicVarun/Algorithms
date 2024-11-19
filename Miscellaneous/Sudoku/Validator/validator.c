//
// Created by @PythonicVarun on 19-11-2024.
//
// This is a modified version of https://csourcecodes.blogspot.com/2016/05/c-program-to-validate-sudoku-checking.html
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

/**
 * @brief Reports an error in the Sudoku grid and terminates the program.
 *
 * This function prints an error message indicating where the Sudoku is
 * incorrect and exits the program.
 *
 * @param errorType The type of error (row, column, or subgrid).
 * @param row The row index where the error occurred.
 * @param col The column index where the error occurred.
 */
void report(char *errorType, int row, int col) {
    printf("\nThe Sudoku is INCORRECT");
    printf("\nError in %s at Row: %d, Column: %d", errorType, row + 1, col + 1);
    exit(0);
}

/**
 * @brief Checks if the given Sudoku board is valid.
 *
 * This function verifies that the Sudoku board satisfies the Sudoku rules:
 * - Each row contains all numbers from 1 to size.
 * - Each column contains all numbers from 1 to size.
 * - Each subgrid (sqrtSize x sqrtSize) contains all numbers from 1 to size.
 *
 * @note Time Complexity: O(n^2), where n is the size of the Sudoku board.
 *       - Checking each row: O(n^2)
 *       - Checking each column: O(n^2)
 *       - Checking each subgrid: O(n^2)
 *       Total: O(3 * n^2) = O(n^2)
 *
 * @note Space Complexity: O(1) - No additional space usage other than variables.
 *
 * @param board The Sudoku board represented as a 2D array.
 * @param size The size of the Sudoku board (size x size).
 */
void check_sudoku(int board[MAX_SIZE][MAX_SIZE], int size) {
    int sqrtSize = sqrt(size);
    int sumCheck = (1 << size) - 1;
    int flag;

    /* ++++++++++++++++++
       Checking Rows
       ++++++++++++++++++
       We check each cell in each row.
       We start with a flag initialized to 0x0000.
       If 1 is found, the zeroth bit of flag is set.
       If 2 is found, the first bit is set, and so on.
       If all digits 1 to size are present, flag's value
       will match sumCheck, indicating the row is correct.
    */
    for (int i = 0; i < size; i++) {
        flag = 0x0000;
        for (int j = 0; j < size; j++) {
            flag |= 1 << (board[i][j] - 1);
        }
        if (flag != sumCheck) {
            report("row", i, size - 1);
        }
    }

    /* ++++++++++++++++++
       Checking Columns
       ++++++++++++++++++
       Similar to row checking. We use a flag to ensure
       each column has all numbers from 1 to size.
    */
    for (int j = 0; j < size; j++) {
        flag = 0x0000;
        for (int i = 0; i < size; i++) {
            flag |= 1 << (board[i][j] - 1);
        }
        if (flag != sumCheck) {
            report("column", size - 1, j);
        }
    }

    /* ++++++++++++++++++
       Checking SubGrids
       ++++++++++++++++++
       We check each subgrid (sqrtSize x sqrtSize).
       The flag is used for each subgrid to ensure all
       numbers from 1 to size are present.
    */
    for (int si = 0; si < sqrtSize; si++) {
        for (int sj = 0; sj < sqrtSize; sj++) {
            flag = 0x0000;
            for (int i = 0; i < sqrtSize; i++) {
                for (int j = 0; j < sqrtSize; j++) {
                    flag |= 1 << (board[si * sqrtSize + i][sj * sqrtSize + j] - 1);
                }
            }
            if (flag != sumCheck) {
                report("subgrid", si * sqrtSize + sqrtSize - 1, sj * sqrtSize + sqrtSize - 1);
            }
        }
    }

    printf("\nThe Sudoku is CORRECT\n");
}

/**
 * @brief The main function to read and validate a Sudoku board.
 *
 * This function prompts the user to enter the size of the Sudoku board,
 * reads the board from user input, and checks if it is valid.
 *
 * @return Returns 0 on successful execution, or 1 if the board size is invalid.
 */
int main() {
    int size;
    int board[MAX_SIZE][MAX_SIZE];
    char c;

    printf("Enter the size of the Sudoku board: ");
    scanf("%d", &size);

    // Validate the size to ensure it is a perfect square
    if (sqrt(size) != (int)sqrt(size)) {
        printf("Invalid board size. Must be a perfect square.\n");
        return 1;
    }

    // Read the Sudoku board from the user
    printf("\nEnter the Sudoku (numbers 1 to %d):\n", size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf(" %c", &c);
            board[i][j] = c - '0';  // Convert character to integer
        }
    }

    check_sudoku(board, size);

    return 0;
}
