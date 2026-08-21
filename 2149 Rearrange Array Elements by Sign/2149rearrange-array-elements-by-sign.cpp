class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> posArray;
        vector<int> negArray;

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0)
                negArray.push_back(nums[i]);
            else
                posArray.push_back(nums[i]);
        }

        int k = 0, i = 0, j = 0;

        while (k < n) {
            nums[k++] = posArray[i++];
            nums[k++] = negArray[j++];
        }

        return nums;
    }
};