class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        // Find the index of 0
        int i = 0;
        for (int j = 0; j < n; ++j) {
            if (nums[j] == 0) {
                i = j;
                break;
            }
        }
        
        // Check if it's a forward cyclic shift
        bool isForward = true;
        for (int j = 0; j < n; ++j) {
            if (nums[(i + j) % n] != j) {
                isForward = false;
                break;
            }
        }
        
        if (isForward) {
            return min(i, n - i + 2);
        }
        bool isBackward = true;
        for (int j = 0; j < n; ++j) {
            if (nums[(i - j + n) % n] != j) {
                isBackward = false;
                break;
            }
        }
        
        if (isBackward) {
            return min(i + 2, n - i);
        }
        
        return -1;
    }
};