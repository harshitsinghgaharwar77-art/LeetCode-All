class Solution {
private:
    bool find(vector<vector<char>>& board, int i, int j, int idx, string& word) {

        // base case
        if (idx >= word.length()) {
            return true;
        }

        int m = board.size();
        int n = board[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$') {
            return false;
        }

        if (board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '$';

        // Don't create directions vector every time
        if (find(board, i + 1, j, idx + 1, word) ||
            find(board, i - 1, j, idx + 1, word) ||
            find(board, i, j + 1, idx + 1, word) ||
            find(board, i, j - 1, idx + 1, word)) {
            return true;
        }

        // backtrack
        board[i][j] = temp;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[0] &&
                    find(board, i, j, 0, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};