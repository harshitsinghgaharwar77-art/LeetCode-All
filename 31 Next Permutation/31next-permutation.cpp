class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // first find the blue gola (break point)
        // break point is the point from where the increasing array starts decreasing from right to left
        int golaIdx = -1;
        for(int i = n-1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                golaIdx = i-1;
                break;
            }
        }

        if(golaIdx != -1){
            int swapIdx = golaIdx;
            for(int j = n-1; j >= golaIdx+1; j--){
                if(nums[j] > nums[golaIdx]){
                    swapIdx = j;
                    break;
                }
            }
            swap(nums[golaIdx], nums[swapIdx]);
        }
        reverse(nums.begin()+golaIdx+1, nums.end());
    }
};