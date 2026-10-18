class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> ans;
        // store the freq of negative integers 50 given in question
        vector<int> freq(51,0);
        int n = nums.size(),i = 0, j =0;
        while(j < n){
            // add the current elemeent if it is negative
            if(nums[j] < 0){
                freq[-nums[j]]++;
            }
            // process the window of size k
            if(j-i+1 == k){
                int cnt = 0, beauty = 0;
                // find the x-th smallest number
                for(int i = 50; i >= 1; i--){
                    cnt += freq[i];
                    if(cnt >= x){
                        beauty = -i;
                        break;
                    }
                }
                ans.push_back(beauty);
                // remove the outgoing element
                if(nums[i] < 0){
                    freq[-nums[i]]--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};