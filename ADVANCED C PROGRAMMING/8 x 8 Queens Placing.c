/*Write a program to place 8 Queens on a chess board such a way that they do not intersect with
 *each other. Please don't refer to the net or discuss with others. Use a minimum four letter variable name.
 *Use as much function as possible. Except scanf and printf don't use any built-in functions.*/

#include <stdio.h>
#include <stdbool.h>

#define MAX 8

// Define the functions

bool solve_8_queens(bool board[MAX][MAX], int cols);
void print_solution(bool board[MAX][MAX]);
bool safe_check(bool board[MAX][MAX], int rows, int cols);
bool check_row(bool board[MAX][MAX], int rows, int cols);
bool check_upper_diagonal(bool board[MAX][MAX], int rows, int cols);
bool check_lower_diagonal(bool board[MAX][MAX], int rows, int cols);

int main() {
    // create a 2-d array for storing the index of the location of queens
    bool board[MAX][MAX] = {false};

    // solve function
    if (solve_8_queens(board, 0)) {
        print_solution(board);
    }

    else {
        printf("No Matches of Queens can be done.");
    }
    return 0;
}

// Function to Solve the 8 Queens problem

bool solve_8_queens(bool board[MAX][MAX], int cols) {

    //To check if all columns are checked
    if (cols >= MAX) return true;


    //Iterate through each row
    for (int rows = 0; rows < MAX; rows++) {

        // check if it is safe to place at this position
        if (safe_check(board, rows, cols)) {
            board[rows][cols] = true;

            //If okay iterate through subsequent columns
            if (solve_8_queens(board, cols + 1)) return true;

            //If it returns false, reverse the current position as false and try to go back again and see
            board[rows][cols] = false;
        }
    }

    //If you cannot place Queen in either of the 8 rows in this column, return false
    return false;
}

bool safe_check(bool board[MAX][MAX], int rows, int cols) {
    if ((check_row(board,rows,cols) && (check_upper_diagonal(board,rows,cols) && (check_lower_diagonal(board,rows,cols))))) {
        return true;
    }
    return false;
}

// check for the current row

bool check_row(bool board[MAX][MAX], int rows, int cols) {
    for (int cur_col = 0; cur_col < cols; cur_col++) {
        if (board[rows][cur_col]) return false;
    }
    return true;
}

// check upper diagonal particularly upper left part

bool check_upper_diagonal(bool board[MAX][MAX], int rows, int cols) {
    //We don't need to check the element at board[rows][cols] so we move
    //to check next upper left diagonal element
    for (int cur_row = rows - 1, check_col = cols - 1; cur_row >= 0 && check_col >= 0; cur_row--, check_col--) {
        if (board[cur_row][check_col]) return false;
    }
    return true;
}

// check lower diagonal particularly lower left part

bool check_lower_diagonal(bool board[MAX][MAX], int rows, int cols) {
    //We don't need to check the element at board[rows][cols] so we move
    //to check next lower left diagonal element
    for (int cur_row = rows + 1, check_col = cols - 1; cur_row < MAX && check_col >= 0; cur_row++, check_col--) {
        if (board[cur_row][check_col]) return false;
    }
    return true;
}

//We don't need to check upper and lower right part as it is checked subsequently by recursive functions

void print_solution(bool board[MAX][MAX]) {
    int count = 1;
    for (int cols = 0; cols < MAX; cols++) {
        for (int rows = 0; rows < MAX; rows++) {
            if (board[rows][cols]) printf("Q%d ",count++);
            else printf("- ");
        }
        printf("\n");
    }
}
