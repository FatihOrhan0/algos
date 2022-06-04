//this file contains a function to solve sudoku puzzles
//Important assumption: given sudoku has a single solution
//future implementation: create a function to check if a sudoku has only one solution, 
//generalize to NxN sudokus

#include <vector>
#include <iostream>
#include <utility>

//checking the validity of a sudoku, helper function
bool checkNum(int num, vector<vector<char> > & board) {
        assert(num >= 0 && num < 10);
        bool arr[27];
        for (int i = 0; i < 27; i++) arr[i] = false;
        for (int i = 0; i < 9; i++) { 
            if (board[i][num] != '.' && arr[board[i][num] - '1'] == true) {
                cout << "1: " << i << " " << num;
                return false;
            }    
            if (board[num][i] != '.' && arr[board[num][i] - '1' + 9] == true) {
                cout << "2: " << i << " " << num;
                return false;
            }
            int col = (num % 3) * 3 + i % 3, row = i / 3 + (num / 3) * 3;
            if (board[row][col] != '.' && arr[board[row][col] - '1' + 18] == true) {
                cout << "3: " << i << " " << num << " " << col << " " << row;
                return false;
            } 
            
            if (board[i][num] != '.') arr[board[i][num] - '1'] = true;
            if (board[num][i] != '.') arr[board[num][i] - '1' + 9] = true;
            if (board[row][col] != '.') arr[board[row][col] - '1' + 18] = true;
        }
        return true;
    }
//main function to check the validity of a sudoku
bool isValidSudoku(vector<vector<char> > & board) {
    for (int i = 0; i < 9; i++) { 
        if (!checkNum(i, board)) return false;
    }
    return true;
}

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
    std::vector<std::vector<char> > board = {{'.','.','.','.','5','.','.','.','.'},
                                            {'.','2','.','1','.','8','.','9','.'},
                                            {'4','.','.','.','.','.','6','.','.'},
                                            {'.','.','.','.','.','7','.','.','.'},
                                            {'.','8','.','3','.','9','.','1','.'},
                                            {'.','.','2','.','.','.','.','.','8'},
                                            {'.','.','.','.','2','.','.','5','.'},
                                            {'.','.','6','5','.','3','9','.','.'},
                                            {'.','3','.','.','7','.','.','.','.'}};
    sudokuSolver(board);
    /* for (unsigned int i = 0; i < board.size(); i++) { 
        for (unsigned int j = 0; j < board[0].size(); j++) { 
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    } */
    std::vector<char> tempRow(9, 'a');
    board.push_back(tempRow);
    board[3].push_back('\n');
    for (auto i : board) { 
        for (auto j : i) { 
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}