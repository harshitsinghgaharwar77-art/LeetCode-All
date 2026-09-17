class Solution {
    private:
    void dfs(int row, int col, vector<vector<int>> &visisted, vector<vector<char>>& board, int delrow[], int delcol[]){
        visisted[row][col] = 1;
        int n = board.size();
        int m = board[0].size();

        // check for top, right, bottom, left
        for(int i = 0; i < 4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
               !visisted[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow, ncol, visisted, board, delrow, delcol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, 1, 0, -1};

        vector<vector<int>> visisted(n, vector<int>(m, 0));

        // traverse first row and last row
        for(int j = 0; j < m; j++){
            // first row
            if(!visisted[0][j] && board[0][j] == 'O'){
                dfs(0, j, visisted, board, delrow, delcol);
            }

            // last row
            if(!visisted[n-1][j] && board[n-1][j] == 'O'){
                dfs(n-1, j, visisted, board, delrow, delcol);
            }
        }

        for(int i = 0; i < n; i++){
            // first column
            if(!visisted[i][0] && board[i][0] == 'O'){
                dfs(i, 0, visisted, board, delrow, delcol);
            }

            // last column
            if(!visisted[i][m-1] && board[i][m-1] == 'O'){
                dfs(i, m-1, visisted, board, delrow, delcol);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visisted[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};