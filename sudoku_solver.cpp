
/*
Sudoku Solver in C++

Concepts Used:
1. Backtracking Algorithm – Used to explore all possible number placements in the Sudoku grid.
2. Recursion – The `solveSudoku()` function calls itself to fill the board step-by-step.
3. 2D Arrays – Used to represent the 9x9 Sudoku grid.
4. Modular Functions – Code is separated into logical functions to check for row, column, and box validity.

Author: [Monty Chandela]
*/

#include <iostream>
#define N 9
using namespace std;

int grid[N][N] = {
    {3, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 0, 0, 0, 0},
    {0, 8, 7, 0, 0, 0, 0, 3, 1},
    {0, 0, 3, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 6, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}
};

bool isPresentInCol(int col, int num){
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool isPresentInRow(int row, int num){
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool isPresentInBox(int boxStartRow, int boxStartCol, int num){
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row + boxStartRow][col + boxStartCol] == num)
                return true;
    return false;
}

void sudokuGrid(){
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){
            if(col == 3 || col == 6)
                cout << " | ";
            cout << grid[row][col] << " ";
        }
        cout << endl;
        if(row == 2 || row == 5){
            for(int i = 0; i<N; i++)
                cout << "---";
            cout << endl;
        }
    }
}

bool findEmptyPlace(int &row, int &col){
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

bool isValidPlace(int row, int col, int num){
    return !isPresentInRow(row, num) && !isPresentInCol(col, num) &&
           !isPresentInBox(row - row % 3 , col - col % 3, num);
}

bool solveSudoku(){
    int row, col;
    if (!findEmptyPlace(row, col))
        return true;
    for (int num = 1; num <= 9; num++){
        if (isValidPlace(row, col, num)){
            grid[row][col] = num;
            if (solveSudoku())
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

int main(){
    if (solveSudoku())
        sudokuGrid();
    else
        cout << "No solution exists";
}
