class Solution {

    static boolean findEmptyCell(char[][] board, int[] emptyCell) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    emptyCell[0] = i;
                    emptyCell[1] = j;
                    return true;
                }
            }
        }
        return false;
    }

    static boolean isSafe(char[][] board, char charValue, int rowIdx, int colIdx) {

        // Row check
        for (int col = 0; col < 9; col++) {
            if (board[rowIdx][col] == charValue) {
                return false;
            }
        }

        // Column check
        for (int row = 0; row < 9; row++) {
            if (board[row][colIdx] == charValue) {
                return false;
            }
        }

        // 3x3 box check
        int startRow = rowIdx - rowIdx % 3;
        int startCol = colIdx - colIdx % 3;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int actualRow = startRow + i;
                int actualCol = startCol + j;

                if (board[actualRow][actualCol] == charValue) {
                    return false;
                }
            }
        }

        return true;
    }

    static boolean solve(char[][] board) {

        int[] emptyCell = new int[2];

        if (!findEmptyCell(board, emptyCell)) {
            return true;
        }

        int rowIdx = emptyCell[0];
        int colIdx = emptyCell[1];

        for (int value = 1; value <= 9; value++) {

            char charValue = (char) (value + '0');

            if (isSafe(board, charValue, rowIdx, colIdx)) {

                board[rowIdx][colIdx] = charValue;

                if (solve(board)) {
                    return true;
                }

                // Backtrack
                board[rowIdx][colIdx] = '.';
            }
        }

        return false;
    }

    public void solveSudoku(char[][] board) {
        solve(board);
    }
}
