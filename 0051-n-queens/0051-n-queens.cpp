class Solution {
    private:
    bool isSafe(int rowIdx, int colIdx, int n, vector<vector<char>> &board){
        int row = rowIdx;
        int col = colIdx;

        // check left side of current row
        while(col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            col--;
        }

        // check upper-left diagonal
        row = rowIdx;
        col = colIdx;
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }

        // check lower-left diagonal
        row = rowIdx;
        col = colIdx;
        while(row < n && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }

    void solve(vector<vector<char>> &board, int n, int colIdx, vector<vector<string>> &ans){
        if(colIdx == n){
            vector<string> temp;
            for(int i = 0; i < n; i++){
                temp.push_back(string(board[i].begin(), board[i].end()));
            }
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < n; i++){
            if(isSafe(i, colIdx, n, board)){
                board[i][colIdx] = 'Q';
                solve(board,n, colIdx+1, ans);
                // backtrack
                board[i][colIdx] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n,'.'));
        vector<vector<string>> ans;
        solve(board, n,0,ans);
        return ans;
    }
};