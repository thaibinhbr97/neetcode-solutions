class Solution {
public:
    // we are going to use unorder_set to store all elements in each row
    // if they are digits, we add them into the set and we can compare its size
    // to the size of that board's row except "." character. If they match
    // its valid. No otherwise.
    // Similar for areColsValid
    bool areRowsValid(vector<vector<char>>& board) {
        unordered_set<int> s;
        int countDigits = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (isdigit(board[i][j])) {
                    countDigits++;
                    s.insert(board[i][j]);
                }
            }
            if (s.size() != countDigits) {
                return false;
            }
            s.clear();
            countDigits = 0;
        }
        return true;
    }
    bool areColsValid(vector<vector<char>>& board) {
        unordered_set<int> s;
        int countDigits = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (isdigit(board[j][i])) {
                    countDigits++;
                    s.insert(board[j][i]);
                }
            }
            if (s.size() != countDigits) {
                return false;
            }
            s.clear();
            countDigits = 0;
        }
        return true;
    }
    // use same idea from unorder_set as well. Traverse through the sub box 
    // insert into our array and have a count to count how many
    bool isSubBoxValid(vector<vector<char>>& board, int x, int y) {
        unordered_set<int> s;
        int countDigits = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (isdigit(board[x + i][y + j])) {
                    countDigits++;
                    s.insert(board[x + i][y + j]);
                }
            }
            if (s.size() != countDigits) {
                return false;
            }
        }
        return true;
    }
    bool areSubBoxesValid(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i += 3) {
            for (int j = 0; j < board.size(); j += 3) {
                if (!isSubBoxValid(board, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // if the sudoku board is valid 
        // the row must be valid -> O(n^2) ~ O(1) since given 9x9 sudoku board
        // the col must be valid -> O(n^2) ~ O(1)
        // the sub box must be valid as well ~ O(1)
        // the time complexity should be O(1)
        // the space complexity should be O(1) 
        if (areRowsValid(board) && areColsValid(board) && areSubBoxesValid(board)) {
            return true;
        }
        return false;
    }
};
