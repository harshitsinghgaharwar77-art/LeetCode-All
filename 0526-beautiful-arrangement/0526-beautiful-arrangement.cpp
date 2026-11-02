
class Solution {
private:
    int solve(int idx, int n, vector<int>& vis){
        // base case
        if(idx > n) return 1;

        int cnt = 0;

        for(int i = 1; i <= n; i++){
            // visited check karo
            if(vis[i]) continue;

            // beautiful check karo
            if(i % idx == 0 || idx % i == 0){
                // visited mark karo
                vis[i] = 1;

                cnt += solve(idx+1,n,vis);

                // backtrack
                vis[i] = 0;
            }
        }

        return cnt;
    }

public:
    int countArrangement(int n) {
        vector<int> vis(n+1,0);
        return solve(1,n,vis);
    }
};
