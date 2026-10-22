class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        // {element, listIdx, idx}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int maxi = INT_MIN;
        for(int i = 0; i < k; i++){
            pq.push({nums[i][0],i,0});
            maxi = max(maxi, nums[i][0]);
        }
        vector<int> ans = {-1000000,1000000};
        while(!pq.empty()){
            vector<int> curr = pq.top();
            pq.pop();
            int mini = curr[0];
            int listIdx = curr[1];
            int idx = curr[2];

            if (maxi - mini < ans[1] - ans[0]){
                ans[0] = mini;
                ans[1] = maxi;
            }
            // decrease the range from minimum side
            if(idx +1 < nums[listIdx].size()){
                int nextElem = nums[listIdx][idx+1];
                pq.push({nextElem, listIdx, idx+1});
                maxi = max(maxi, nextElem);
            }else break;
        }
        return ans;
    }
};