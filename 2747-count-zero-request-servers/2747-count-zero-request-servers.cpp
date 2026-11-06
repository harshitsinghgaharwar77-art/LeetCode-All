class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        vector<pair<int,int>> q;

        for(int i = 0; i < queries.size(); i++){
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());
        sort(logs.begin(), logs.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });

        unordered_map<int,int> mp;
        vector<int> ans(queries.size());

        int l = 0, r = 0;
        int cnt = 0;

        for(auto &it : q){
            int start = it.first - x;
            int end = it.first;
            int idx = it.second;

            // Add logs within the current window
            while(r < logs.size() && logs[r][1] <= end){
                mp[logs[r][0]]++;

                if(mp[logs[r][0]] == 1){
                    cnt++;
                }

                r++;
            }

            // Remove logs outside the current window
            while(l < r && logs[l][1] < start){
                mp[logs[l][0]]--;

                if(mp[logs[l][0]] == 0){
                    cnt--;
                }

                l++;
            }

            ans[idx] = n - cnt;
        }

        return ans;
    }
};