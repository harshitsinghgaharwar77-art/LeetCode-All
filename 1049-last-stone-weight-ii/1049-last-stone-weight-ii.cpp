
class Solution {
    int solveMem(vector<int>& stones, int idx, int sum, int target, vector<vector<int>>&dp){
        // base case
        if(idx == stones.size()) return sum;
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int incl = 0;
        // include
        if(sum + stones[idx] <= target){
            incl = solveMem(stones, idx+1,sum+stones[idx],target,dp);
        }
        int excl = solveMem(stones, idx+1,sum,target,dp);
        return dp[idx][sum] = max(incl,excl);
    }
    
    int solveTab(vector<int>&stones){
        int sum = 0;
        int n = stones.size();
        for(int s : stones) sum += s;
        int target = sum/2;
        vector<vector<int>> dp(n+1, vector<int>(target + 1, 0));
        for(int idx = n-1; idx >= 0; idx--){
            for(int t = 0; t <= target; t++){
                int incl = 0;
                // include
                if(stones[idx] <= t){
                    incl = stones[idx] + dp[idx+1][t - stones[idx]];
                }
                int excl = dp[idx+1][t];
                dp[idx][t] = max(incl,excl);
            }
        }
        return dp[0][target];
    }

    int solveFinal(vector<int>&stones){
        int sum = 0;
        int n = stones.size();
        for(int s : stones) sum += s;
        int target = sum/2;
        vector<int> next(target+1,0);
        for(int idx = n-1; idx >= 0; idx--){
            vector<int> curr(target+1,0);
            for(int t = 0; t <= target; t++){
                int incl = 0;
                // include
                if(stones[idx] <= t){
                    incl = stones[idx] + next[t - stones[idx]];
                }
                int excl = next[t];
                curr[t] = max(incl,excl);
            }
            next = curr;
        }
        return next[target];
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        // algo
        //1: find the sum/2 of all stones
        //2: this will create two piles
        //3: or goal is to minimise the difference 
        //4: so we will take aur ans closest to the sum/2
        //5: return sum - 2*ans (minimum)
        int sum = 0;
        for(int s : stones) sum += s;
        int ans = solveTab(stones);
        return sum - 2*ans;
    }
};
