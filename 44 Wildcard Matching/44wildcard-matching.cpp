class Solution {
private:
// Recursive solution
bool solveRec(string s, string p, int i, int j) {
    // Base cases
    if (i < 0 && j < 0) {
        return true;
    }
    // Pattern exhausted but string is still left
    if (i >= 0 && j < 0) {
        return false;
    }
    // String exhausted but pattern is still left
    if (i < 0 && j >= 0) {
        // Remaining pattern must contain only '*'
        for (int k = 0; k <= j; k++) {
            if (p[k] != '*') {
                return false;
            }
        }
        return true;
    }
    // Characters match
    if (s[i] == p[j] || p[j] == '?') {
        return solveRec(s, p, i - 1, j - 1);
    }
    // '*' can:
    // 1. Match one character -> i-1, j
    // 2. Match zero characters -> i, j-1
    else if (p[j] == '*') {
        return solveRec(s, p, i - 1, j) || solveRec(s, p, i, j - 1);
    }
    // No match
    else {
        return false;
    }
}


// Top down approach
int solveMem(string s, string p, int i, int j, vector<vector<int>> &dp){
    // Base cases
    if (i < 0 && j < 0) {
        return true;
    }
    // Pattern exhausted but string is still left
    if (i >= 0 && j < 0) {
        return false;
    }
    // String exhausted but pattern is still left
    if (i < 0 && j >= 0) {
        // Remaining pattern must contain only '*'
        for (int k = 0; k <= j; k++) {
            if (p[k] != '*') {
                return false;
            }
        }
        return true;
    }

    // FIX 1: Check if already calculated
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    // Characters match
    if (s[i] == p[j] || p[j] == '?') {
        return dp[i][j] = solveMem(s, p, i - 1, j - 1, dp);
    }
    // '*' can:
    // 1. Match one character -> i-1, j
    // 2. Match zero characters -> i, j-1
    else if (p[j] == '*') {
        return dp[i][j] = solveMem(s, p, i - 1, j, dp) || 
                          solveMem(s, p, i, j - 1, dp);
    }
    // No match
    else {
        return dp[i][j] = false;
    }
}


// Tabulation method
bool solveTab(string s, string p){
    int n = s.length();
    int m = p.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    dp[0][0] = true;

    for(int j = 1; j <= m; j++){
        bool flag = true;

        for(int k = 1; k <= j; k++){
            if(p[k-1] != '*'){
                flag = false;
                break;
            }
        }

        dp[0][j] = flag;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s[i-1] == p[j-1] || p[j-1] == '?')
                dp[i][j] = dp[i-1][j-1];

            else if(p[j-1] == '*')
                dp[i][j] = (dp[i-1][j] || dp[i][j-1]);

            else
                dp[i][j] = false;
        }
    }

    return dp[n][m];
}


// Space optimised solution
bool solve(string s, string p){
    int n = s.length();
    int m = p.length();

    vector<int> prev(m+1,0);
    vector<int> curr(m+1,0);

    prev[0] = true;

    for(int j = 1; j <= m; j++){
        bool flag = true;

        for(int k = 1; k <= j; k++){
            if(p[k-1] != '*'){
                flag = false;
                break;
            }
        }

        prev[j] = flag;
    }

    for(int i = 1; i <= n; i++){

        // FIX 2: Empty pattern cannot match non-empty string
        curr[0] = false;

        for(int j = 1; j <= m; j++){
            if(s[i-1] == p[j-1] || p[j-1] == '?')
                curr[j] = prev[j-1];

            else if(p[j-1] == '*')
                curr[j] = (prev[j] || curr[j-1]);

            else
                curr[j] = false;
        }

        // FIX 3: Move current row to previous row
        prev = curr;
    }

    return prev[m];
}


public:

bool isMatch(string s, string p) {

    // int n = s.length();
    // int m = p.length();
    // vector<vector<int>> dp(n, vector<int>(m, -1));

    return solve(s, p);
}

};