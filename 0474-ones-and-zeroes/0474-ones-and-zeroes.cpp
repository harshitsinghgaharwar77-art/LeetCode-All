
class Solution {
    int solve(vector<string>& strs, int m, int n, int idx){
        if(idx == strs.size()) return 0;
        int ones = 0, zeroes = 0;
        for(char ch : strs[idx]){
            if(ch == '0') zeroes++;
            else ones++;
        }
        // exlcude
        int excl = solve(strs, m,n,idx+1);
        // incl
        int incl = 0;
        if(zeroes <= m && ones <= n){
            incl = 1 + solve(strs, m-zeroes, n-ones, idx+1);
        }
        return max(incl, excl);
    }

    int solveMem(vector<string>& strs, int m, int n, int idx, vector<vector<vector<int>>> &dp){
        if(idx == strs.size()) return 0;
        if(dp[idx][m][n] != -1) return dp[idx][m][n];
        int ones = 0, zeroes = 0;
        for(char ch : strs[idx]){
            if(ch == '0') zeroes++;
            else ones++;
        }
        // exlcude
        int excl = solveMem(strs, m,n,idx+1,dp);
        // incl
        int incl = 0;
        if(zeroes <= m && ones <= n){
            incl = 1 + solveMem(strs, m-zeroes, n-ones, idx+1,dp);
        }
        return dp[idx][m][n] = max(incl, excl);
    }

    int solveTab(vector<string>& strs, int m, int n){
        int sz = strs.size();
        vector<vector<vector<int>>> dp(sz+1, vector<vector<int>>(m+1, vector<int>(n+1,0)));
        for(int idx = sz-1; idx >= 0; idx--){
            int ones = 0, zeroes = 0;
            for(char ch: strs[idx]){
                if(ch == '0') zeroes++;
                else ones++;
            }
            for(int i = 0; i <= m; i++){
                for(int j = 0; j <= n; j++){
                    // exlcude
                    int excl = dp[idx+1][i][j];
                    // incl
                    int incl = 0;
                    if(zeroes <= i && ones <= j){
                        incl = 1 + dp[idx+1][i-zeroes][j-ones];
                    }
                    dp[idx][i][j] = max(incl, excl);
                }
            }
        }
        return dp[0][m][n];
    }

    int solveFinal(vector<string>& strs, int m, int n){
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(string s : strs){
            int zeros = 0, ones = 0;
            for(char ch : s){
                if(ch == '0') zeros++;
                else ones++;
            }
            for(int i = m; i >= zeros; i--){
                for(int j = n; j >= ones; j--){
                    dp[i][j] = max(dp[i][j], 1 + dp[i-zeros][j-ones]);
                }
            }
        }
        return dp[m][n];
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // approach
        //1. track the count of zeroes and ones
        //2. include when zeroes < m and vice versa
        //3. exclude as usual
        //4. return max(incl,excl)
        return solveFinal(strs,m,n);
    }
};
