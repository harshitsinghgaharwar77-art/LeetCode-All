class Solution {
private:
    // Recursive solution
    int solveRec(vector<int>& obstacles, int currLane, int currPos) {
        // Base case
        int n = obstacles.size() - 1;
        if (currPos == n) {
            return 0;
        }

        // Move forward if next position is free
        if (obstacles[currPos + 1] != currLane) {
            return solveRec(obstacles, currLane, currPos + 1);
        } else {
            // Side jump
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++) {
                if (i != currLane && obstacles[currPos] != i) {
                    ans = min(ans, 1 + solveRec(obstacles, i, currPos));
                }
            }
            return ans;
        }
    }

    // Top down approach
    int solveMem(vector<int>& obstacles, int currLane, int currPos,
                 vector<vector<int>>& dp) {
        // Base case
        int n = obstacles.size() - 1;
        if (currPos == n) {
            return 0;
        }
        if (dp[currLane][currPos] != -1) {
            return dp[currLane][currPos];
        }
        // Move forward if next position is free
        if (obstacles[currPos + 1] != currLane) {
            return solveRec(obstacles, currLane, currPos + 1);
        } else {
            // Side jump
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++) {
                if (i != currLane && obstacles[currPos] != i) {
                    ans = min(ans, 1 + solveRec(obstacles, i, currPos));
                }
            }
            dp[currLane][currPos] = ans;
            return dp[currLane][currPos];
        }
    }

    // Tabulation method
    int solveTab(vector<int>& obstacles) {
        int n = obstacles.size() - 1;

        vector<vector<int>> dp(4, vector<int>(n + 1, INT_MAX));

        for (int lane = 1; lane <= 3; lane++) {
            dp[lane][n] = 0;
        }

        for (int pos = n - 1; pos >= 0; pos--) {
            for (int lane = 1; lane <= 3; lane++) {

                // Move forward
                if (obstacles[pos + 1] != lane) {
                    dp[lane][pos] = dp[lane][pos + 1];
                } else {
                    int ans = INT_MAX;

                    // Side jump at current position
                    for (int i = 1; i <= 3; i++) {
                        if (i != lane && obstacles[pos] != i) {
                            ans = min(ans, 1 + dp[i][pos + 1]);
                        }
                    }

                    dp[lane][pos] = ans;
                }
            }
        }

        return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
    }
    // Space optimised solution
    int solve(vector<int>& obstacles){
        int n = obstacles.size() - 1;
        vector<int> curr(4,1e9);
        vector<int> next(4,1e9);

        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for(int currPos = n-1; currPos >= 0; currPos--){
            for(int currLane = 1; currLane <= 3; currLane++){
                if(obstacles[currPos+1] != currLane){
                    curr[currLane] = next[currLane];
                }else{
                    int ans = 1e9;
                    for(int i = 0; i <= 3; i++){
                        if(currLane != i && obstacles[currPos] != i){
                            ans = min(ans, 1+next[i]);
                        }
                    }
                    curr[currLane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2], min(1+next[1], 1+next[3]));
    }

public:
    int minSideJumps(vector<int>& obstacles) {
        // return solveRec(obstacles, 2, 0);
        //  vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        //  return solveMem(obstacles, 2, 0, dp);
        //return solveTab(obstacles);
        return solve(obstacles);
    }
};