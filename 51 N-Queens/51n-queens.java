class Solution {

    static boolean isSafe(int rowIdx, int colIdx, int n, char[][] board) {

        int row = rowIdx;
        int col = colIdx;

        // Check left side of current row
        while (col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            col--;
        }

        // Check upper-left diagonal
        row = rowIdx;
        col = colIdx;
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row--;
            col--;
        }

        // Check lower-left diagonal
        row = rowIdx;
        col = colIdx;
        while (row < n && col >= 0) {
            if (board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }

        return true;
    }

    static void solve(char[][] board, int n, int colIdx,
                      List<List<String>> ans) {

        if (colIdx == n) {
            List<String> temp = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                temp.add(new String(board[i]));
            }
            ans.add(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (isSafe(i, colIdx, n, board)) {

                board[i][colIdx] = 'Q';

                solve(board, n, colIdx + 1, ans);

                // Backtrack
                board[i][colIdx] = '.';
            }
        }
    }

    public List<List<String>> solveNQueens(int n) {

        char[][] board = new char[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(board[i], '.');
        }

        List<List<String>> ans = new ArrayList<>();

        solve(board, n, 0, ans);

        return ans;
    }
}