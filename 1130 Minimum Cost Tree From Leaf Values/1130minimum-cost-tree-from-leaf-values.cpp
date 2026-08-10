class Solution {
    // Recursive solution
    int solveRec(vector<int>& arr, map<pair<int, int>, int> &maxi, int left, int right){
        // base case
        if(left == right){
            return 0;   // leaf node
        }
        int ans = INT_MAX;
        for(int i = left; i < right; i++){
            ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solveRec(arr, maxi, left, i) + solveRec(arr, maxi, i+1, right));
        }
        return ans;
    }

    // Top down approach
    int solveMem(vector<int>& arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp){
        // base case
        if(left == right){
            return 0;   // leaf node
        }
        if(dp[left][right] != -1){
            return dp[left][right];
        }
        int ans = INT_MAX;
        for(int i = left; i < right; i++){
            ans = min(ans, maxi[{left, i}] * maxi[{i+1, right}] + solveMem(arr, maxi, left, i,dp) + solveMem(arr, maxi, i+1, right,dp));
        }
        return dp[left][right] = ans;
    }

    // Tabulation method
    int solveTab(vector<int>& arr, map<pair<int, int>, int>& maxi) {
        int n = arr.size();
        // dp[left][right] = minimum cost for arr[left...right]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // Length 2 -> Length n
        for (int len = 2; len <= n; len++) {
            for (int left = 0; left <= n - len; left++) {
                int right = left + len - 1;
                int ans = INT_MAX;
                for (int i = left; i < right; i++) {
                    int cost = maxi[{left, i}] * maxi[{i + 1, right}] + dp[left][i] + dp[i + 1][right];
                    ans = min(ans, cost);
                }
                dp[left][right] = ans;
            }
        }
        return dp[0][n - 1];
    }



public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int, int>, int> maxi;
        for(int i = 0; i < n; i++){
            maxi[{i,i}] = arr[i];
            for(int j = i+1; j < n; j++){
                maxi[{i,j}] = max(arr[j], maxi[{i, j-1}]);
            }
        }
        // vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        int ans = solveTab(arr, maxi);
        return ans;
    }
};