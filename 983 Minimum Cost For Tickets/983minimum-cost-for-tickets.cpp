#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive solution
    int solveRec(vector<int> &days, vector<int> &cost, int idx) {
        if (idx >= days.size())
            return 0;

        int option1 = cost[0] + solveRec(days, cost, idx + 1);

        int i;
        for (i = idx; i < days.size() && days[i] < days[idx] + 7; i++);
        int option2 = cost[1] + solveRec(days, cost, i);

        for (i = idx; i < days.size() && days[i] < days[idx] + 30; i++);
        int option3 = cost[2] + solveRec(days, cost, i);

        return min(option1, min(option2, option3));
    }

    // Memoization
    int solveMem(vector<int> &days, vector<int> &cost, int idx,
                 vector<int> &dp) {
        if (idx >= days.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int option1 = cost[0] + solveMem(days, cost, idx + 1, dp);

        int i;
        for (i = idx; i < days.size() && days[i] < days[idx] + 7; i++);
        int option2 = cost[1] + solveMem(days, cost, i, dp);

        for (i = idx; i < days.size() && days[i] < days[idx] + 30; i++);
        int option3 = cost[2] + solveMem(days, cost, i, dp);

        return dp[idx] = min(option1, min(option2, option3));
    }

    // Tabulation
    int solveTab(vector<int> &days, vector<int> &cost) {
        int n = days.size();
        vector<int> dp(n + 1, 0);

        for (int k = n - 1; k >= 0; k--) {
            int option1 = cost[0] + dp[k + 1];

            int i;
            for (i = k; i < n && days[i] < days[k] + 7; i++);
            int option2 = cost[1] + dp[i];

            for (i = k; i < n && days[i] < days[k] + 30; i++);
            int option3 = cost[2] + dp[i];

            dp[k] = min(option1, min(option2, option3));
        }

        return dp[0];
    }

    // Space Optimized
    int solve(vector<int> &days, vector<int> &cost) {
        int ans = 0;

        queue<pair<int, int>> week, month;

        for (int day : days) {

            while (!week.empty() && week.front().first + 7 <= day)
                week.pop();

            while (!month.empty() && month.front().first + 30 <= day)
                month.pop();

            week.push({day, ans + cost[1]});
            month.push({day, ans + cost[2]});

            ans = min(ans + cost[0],
                      min(week.front().second, month.front().second));
        }

        return ans;
    }

    int mincostTickets(vector<int> &days, vector<int> &costs) {
        // return solveRec(days, costs, 0);

        // vector<int> dp(days.size(), -1);
        // return solveMem(days, costs, 0, dp);

        // return solveTab(days, costs);

        return solve(days, costs);
    }
};