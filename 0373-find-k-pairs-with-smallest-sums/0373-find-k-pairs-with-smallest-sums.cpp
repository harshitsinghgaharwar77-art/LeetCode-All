class Solution {
public:
    typedef pair<int,vector<int>> p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<p, vector<p>, greater<p>> pq;
        int m = nums1.size(), n =nums2.size();
        vector<vector<int>> ans;
        set<pair<int,int>> vis;
        int sum = nums1[0] + nums2[0];
        pq.push({sum,{0,0}});
        vis.insert({0,0});
        while(k-- && !pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int i = temp.second[0];
            int j = temp.second[1];
            ans.push_back({nums1[i], nums2[j]});
            // process (i,j+1)
            if(j+1 < n && vis.find({i,j+1}) == vis.end()){
                pq.push({nums1[i] + nums2[j+1], {i,j+1}});
                vis.insert({i,j+1});
            }
            // process (i+1,j)
            if(i+1 < m && vis.find({i+1,j}) == vis.end()){
                pq.push({nums1[i+1] + nums2[j], {i+1,j}});
                vis.insert({i+1,j});
            }
        }
        return ans;
    }
};