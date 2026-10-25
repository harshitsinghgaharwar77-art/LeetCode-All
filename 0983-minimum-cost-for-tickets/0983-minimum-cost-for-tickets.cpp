
class Solution {
    int solve(vector<int>& days, vector<int>& costs,int idx){
        // base case
        if(idx >= days.size()) return 0;
        int option1 = costs[0] + solve(days, costs, idx+1);
        int i;
        for(i = idx; i < days.size() && days[i] < days[idx]+7; i++);
        int option2 = costs[1] + solve(days, costs, i);
        for(i = idx; i < days.size() && days[i] < days[idx]+30; i++);
        int option3 = costs[2] + solve(days, costs, i);
        return min(option1, min(option2, option3));
    }
    int solveMem(vector<int>& days, vector<int>& costs,int idx, vector<int> &dp){
        // base case
        if(idx >= days.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int option1 = costs[0] + solveMem(days, costs, idx+1,dp);
        int i;
        for(i = idx; i < days.size() && days[i] < days[idx]+7; i++);
        int option2 = costs[1] + solveMem(days, costs, i,dp);
        for(i = idx; i < days.size() && days[i] < days[idx]+30; i++);
        int option3 = costs[2] + solveMem(days, costs, i,dp);
        return dp[idx] = min(option1, min(option2, option3));
    }
    int solveTab(vector<int>& days, vector<int>& costs){
        int n = days.size();
        vector<int> dp(n+1,0);
        dp[n] = 0;
        for(int idx = n-1; idx >= 0; idx--){
            int option1 = costs[0] + dp[idx+1];
            int i;
            for(i = idx; i < days.size() && days[i] < days[idx]+7; i++);
            int option2 = costs[1] + dp[i];
            for(i = idx; i < days.size() && days[i] < days[idx]+30; i++);
            int option3 = costs[2] + dp[i];
            dp[idx] = min(option1, min(option2, option3));
        }
        return dp[0];
    }
    int solveFinal(vector<int>& days, vector<int>& costs){
        // take queue for monthly and weekly pass
        // where int,int -> day, cost
        int ans = 0;
        queue<pair<int,int>> week, month;
        for(int day: days){
            // remoove invalid days
            while(!week.empty() && week.front().first + 7 <= day){
                week.pop();
            }
            while(!month.empty() && month.front().first + 30 <= day){
                month.pop();
            }
            // day aur ajj tak ki cost kitni hui
            week.push({day, ans + costs[1]});
            month.push({day, ans + costs[2]});
            ans = min(ans + costs[0],
                      min(week.front().second, month.front().second));
        }
        return ans;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // int n = days.size();
        // vector<int> dp(n+1,-1);
        return solveFinal(days, costs);
    }
};
