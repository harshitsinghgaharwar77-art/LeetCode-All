class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int num: nums) mpp[num]++;
        vector<vector<int>> bucket(n+1);
        // index -> freq;
        // value -> elements;
        // bucket[i] -> element having i frequency
        for(auto &i : mpp){
            int val = i.first;
            int freq = i.second;
            bucket[freq].push_back(val);
        }
        // build result
        // put elements from right to left from the bucket to find the maximum frequency element
        for(int i = n; i >= 0; i--){
            if(bucket[i].size() == 0) continue;
            while(bucket[i].size() > 0 && k > 0){
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return ans;
    }
};