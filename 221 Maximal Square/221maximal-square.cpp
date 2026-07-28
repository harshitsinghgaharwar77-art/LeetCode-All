class Solution {
private:
    // Recursive solution
    int solveRec(vector<vector<char>> &mat, int i, int j, int &maxi) {
        if (i >= mat.size() || j >= mat[0].size()) {
            return 0;
        }

        int right = solveRec(mat, i, j + 1, maxi);
        int diag = solveRec(mat, i + 1, j + 1, maxi);
        int down = solveRec(mat, i + 1, j, maxi);

        if (mat[i][j] == '1') {
            int ans = 1 + min(right, min(diag, down));
            maxi = max(maxi, ans);
            return ans;
        }

        return 0;
    }

    // Memoization
    int solveMem(vector<vector<char>> &mat, int i, int j, int &maxi,
                 vector<vector<int>> &dp) {

        if (i >= mat.size() || j >= mat[0].size()) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int right = solveMem(mat, i, j + 1, maxi, dp);
        int diag = solveMem(mat, i + 1, j + 1, maxi, dp);
        int down = solveMem(mat, i + 1, j, maxi, dp);

        if (mat[i][j] == '1') {
            dp[i][j] = 1 + min(right, min(diag, down));
            maxi = max(maxi, dp[i][j]);
        }
        else {
            dp[i][j] = 0;
        }

        return dp[i][j];
    }

    // Tabulation
    int solveTab(vector<vector<char>> &mat, int &maxi) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                int right = dp[i][j + 1];
                int diag = dp[i + 1][j + 1];
                int down = dp[i + 1][j];

                if (mat[i][j] == '1') {
                    dp[i][j] = 1 + min(right, min(diag, down));
                    maxi = max(maxi, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }

        return maxi;
    }

    // Space Optimized
    int solveSO(vector<vector<char>> &mat, int &maxi) {

        int n = mat.size();
        int m = mat[0].size();

        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);

        for (int i = n - 1; i >= 0; i--) {

            for (int j = m - 1; j >= 0; j--) {

                int right = curr[j + 1];
                int diag = next[j + 1];
                int down = next[j];

                if (mat[i][j] == '1') {
                    curr[j] = 1 + min(right, min(diag, down));
                    maxi = max(maxi, curr[j]);
                }
                else {
                    curr[j] = 0;
                }
            }

            next = curr;
        }

        return maxi;
    }

public:
    int maximalSquare(vector<vector<char>>& matrix) {

        if (matrix.empty() || matrix[0].empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        int maxi = 0;

        // Recursive
        // solveRec(matrix, 0, 0, maxi);

        // Memoization
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // solveMem(matrix, 0, 0, maxi, dp);

        // Tabulation
        // solveTab(matrix, maxi);

        // Space Optimized
        solveSO(matrix, maxi);

        return maxi * maxi;
    }
};