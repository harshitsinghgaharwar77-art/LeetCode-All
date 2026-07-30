class Solution {
private:
// Recurisve solution
    int solveRec(int idx, int end, vector<int>& slices, int n) {
        if (n == 0) return 0;
        if (idx > end)  return INT_MIN;
        // include
        int incl = slices[idx] + solveRec(idx + 2, end, slices, n - 1);
        // exclude
        int excl = solveRec(idx + 1, end, slices, n);
        return max(incl, excl);
    }

    // Top down approach
    int solveMem(int idx, int end, vector<int>& slices, int n, vector<vector<int>> &dp){
        // base case
        if (n == 0) return 0;
        if (idx > end)  return INT_MIN;
        if(dp[idx][n] != -1){
            return dp[idx][n];
        }
        // include
        int incl = slices[idx] + solveMem(idx + 2, end, slices, n - 1,dp);
        // exclude
        int excl = solveMem(idx + 1, end, slices, n,dp);
        dp[idx][n] = max(incl, excl);
        return dp[idx][n];
    }


    // Tabulation method
    int solveTab(vector<int>& slices){
        int k = slices.size();
        vector<vector<int>> dp1(k+2, vector<int>(k+2,0));
        vector<vector<int>> dp2(k+2, vector<int>(k+2,0));
        for(int idx  = k-2; idx >= 0; idx--){
            for(int n = 1; n <= k/3; n++){
                int incl = slices[idx] + dp1[idx+2][n-1];
                int excl = 0 + dp1[idx+1][n];

                dp1[idx][n] = max(incl, excl);
            }
        }
        int case1 = dp1[0][k/3];
        for(int idx  = k-1; idx >= 1; idx--){
            for(int n = 1; n <= k/3; n++){
                int incl = slices[idx] + dp2[idx+2][n-1];
                int excl = 0 + dp2[idx+1][n];

                dp2[idx][n] = max(incl, excl);
            }
        }
        int case2 = dp2[1][k/3];
        return max(case1, case2);
    }


    // Space optimised solution
    int solve(vector<int>& slices){
        int k = slices.size();
        vector<int> prev1(k+1,0);
        vector<int> curr1(k+1,0);
        vector<int> next1(k+1,0);

        vector<int> prev2(k+1,0);
        vector<int> curr2(k+1,0);
        vector<int> next2(k+1,0);

        for(int idx  = k-2; idx >= 0; idx--){
            for(int n = 1; n <= k/3; n++){
                int incl = slices[idx] + next1[n-1];
                int excl = 0 + curr1[n];

                prev1[n] = max(incl, excl);
            }
            next1 = curr1;
            curr1 = prev1;
        }
        int case1 = curr1[k/3];
        for(int idx  = k-1; idx >= 1; idx--){
            for(int n = 1; n <= k/3; n++){
                int incl = slices[idx] + next2[n-1];
                int excl = 0 + curr2[n];

                prev2[n] = max(incl, excl);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        int case2 = curr2[k/3];
        return max(case1, case2);
    }


public:
    int maxSizeSlices(vector<int>& slices) {
        // int k = slices.size();
        // vector<vector<int>> dp1(k, vector<int>(k,-1));
        // int case1 = solveMem(0, k - 2, slices, k / 3, dp1);
        // vector<vector<int>> dp2(k, vector<int>(k,-1));
        // int case2 = solveMem(1, k - 1, slices, k / 3, dp2);
        // // return max(case1, case2);
        
        // return max(case1, case2);

        return solveTab(slices);
    }
};