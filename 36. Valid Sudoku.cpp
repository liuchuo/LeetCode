36. Valid Sudoku 
My Submissions QuestionEditorial Solution
Total Accepted: 70853 Total Submissions: 232765 Difficulty: Easy
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

Subscribe to see which companies asked this question


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int book[10];
        memset(book, 0, sizeof(int)*10);
        //每一列
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                if(book[board[i][j] - '0'] == 0)
                    book[board[i][j] - '0'] = 1;
                else
                    return false;
            }
            memset(book, 0, sizeof(int) * 10);
        }
        //每一行
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[j][i] == '.') continue;
                if(book[board[j][i] - '0'] == 0)
                    book[board[j][i] - '0'] = 1;
                else
                    return false;
            }
            memset(book, 0, sizeof(int) * 10);
        }
        //每个小九宫格
        for(int m = 0; m <= 6; m = m + 3) {
            for(int i = 0; i <= 8; i++) {
                if(i % 3 == 0)
                     memset(book, 0, sizeof(int) * 10);
                for(int j = 0; j <= 2; j++) {
                    if(board[i][j + m] == '.') continue;
                    if(book[board[i][j + m] - '0'] == 0)
                        book[board[i][j + m] - '0'] = 1;
                    else
                        return false;
                }
            }
        }
        return true;
    }
};
