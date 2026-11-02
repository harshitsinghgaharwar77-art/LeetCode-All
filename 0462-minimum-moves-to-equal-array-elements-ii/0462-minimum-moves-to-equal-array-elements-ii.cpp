
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        // Sort the array
        sort(nums.begin(), nums.end());
        // Find median
        int median = nums[n / 2];
        int moves = 0;
        // Calculate total moves required
        for(int i = 0; i < n; i++){
            moves += abs(nums[i] - median);
        }
        return moves;
    }
};
