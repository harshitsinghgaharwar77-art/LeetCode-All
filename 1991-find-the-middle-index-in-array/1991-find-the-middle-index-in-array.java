class Solution {
    public int findMiddleIndex(int[] nums) {
        int n = nums.length;
        int sum = 0;
        int leftsum = 0;
        for(int num : nums) sum += num;
        for(int i = 0; i < n; i++){
            int  rightsum = sum - leftsum-nums[i];
            if(rightsum == leftsum) return i;
            leftsum += nums[i];
        }
        return -1;
    }
}