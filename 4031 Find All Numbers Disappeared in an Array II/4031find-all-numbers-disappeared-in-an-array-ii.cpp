class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();

        set<int> st;

        for(int i = 0; i < n; i++){
            st.insert(nums[i]);
        }

        for(int i = lower; i <= upper; i++){
            if(st.find(i) == st.end()){
                temp.push_back(i);
            }
        }

        if(temp.empty())
            return ans;

        int start = temp[0];

        for(int i = 1; i < temp.size(); i++){
            if(temp[i] != temp[i - 1] + 1){
                ans.push_back({start, temp[i - 1]});
                start = temp[i];
            }
        }

        ans.push_back({start, temp.back()});

        return ans;
    }
};