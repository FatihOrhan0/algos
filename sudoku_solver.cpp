//this file contains a function to solve sudoku puzzles
//Important assumption: given sudoku has a single solution
//future implementation: create a function to get all solutions to a given sudoku

#include <vector>
#include <iostream>
#include <utility>

char numbers[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool checkCol(std::vector<std::vector<char> > & board,
              int row, char val) {
    for (int i = 0; i < 9; i++) { 
        if (board[row][i] == val)
            return false;
    }
    return true;
}

bool checkRow(std::vector<std::vector<char> > & board,
              int col, char val) {
    for (int i = 0; i < 9; i++) { 
        if (board[i][col] == val)
            return false;
    }
    return true;
}

bool checkSquare(std::vector<std::vector<char> > & board,
                 int row, int col, char val) {
    row -= row % 3;
    col -= col % 3;
    for (int i = row; i < row + 3; i++) {
        for (int j = col; j < col + 3; j++) {
            if (board[i][j] == val)
                return false;
        }
    }
    return true;
}

const std::vector<std::pair<int, int> > findEmptyOnes(
std::vector<std::vector<char> > & board) { 
    std::vector<std::pair<int, int> > empties;
    for (unsigned int i = 0; i < board.size(); i++) { 
        for (unsigned int j = 0; j < board[0].size(); j++) { 
            if (board[i][j] == '.') { 
                empties.push_back(std::make_pair(i, j));
            }
        }
    }
    return empties;
}

void sudokuSolver(std::vector<std::vector<char> > & board) { 
    std::vector<std::pair<int, int> > empties = findEmptyOnes(board);
    for (unsigned int i = 0; i < empties.size(); i++) { 
        for (unsigned int j = 0; j < 9; j++) { 
            //if we can place a number to the current cell, place it
            if (checkCol(board, empties[i].first, numbers[j]) &&
            checkRow(board, empties[i].second, numbers[j]) && 
            checkSquare(board, empties[i].first, empties[i].second, numbers[j])) { 
                board[empties[i].first][empties[i].second] = numbers[j];
                break;
            }
        }
        //if the  placement could not be done, start backtracking
        if (board[empties[i].first][empties[i].second] == '.') { 
            bool changed = true;
            while (i > 0 && changed) { 
                i--; 
                int index = (int) board[empties[i].first][empties[i].second]
                 - (int) '1';   
                board[empties[i].first][empties[i].second] = '.';
                for (int j = index + 1; j < 9; j++) { 
                    if (checkCol(board, empties[i].first, numbers[j]) &&
                        checkRow(board, empties[i].second, numbers[j]) && 
                        checkSquare(board, empties[i].first, empties[i].second,
                        numbers[j])) { 
                board[empties[i].first][empties[i].second] = numbers[j];
                changed = false;
                break;
                    }
                }
            }
        } 
    }
}


int main() { 
    std::vector<std::vector<char> > board = {{'5','3','.','.','7','.','.','.','.'},
                                            {'6','.','.','1','9','5','.','.','.'},
                                            {'.','9','8','.','.','.','.','6','.'},
                                            {'8','5','9','7','6','1','4','2','3'},
                                            {'4','.','.','8','.','3','.','.','1'},
                                            {'7','.','.','.','2','.','.','.','6'},
                                            {'.','6','.','.','.','.','2','8','.'},
                                            {'.','.','.','4','1','9','.','.','5'},
                                            {'.','.','.','.','8','.','.','7','9'}};
    sudokuSolver(board);
    for (int i = 0; i < 9; i++) { 
        for (int j = 0; j < 9; j++) { 
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}