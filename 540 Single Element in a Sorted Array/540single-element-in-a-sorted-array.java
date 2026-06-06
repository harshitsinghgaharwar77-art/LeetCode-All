class Solution {
    public int singleNonDuplicate(int[] nums) {
        int s = 0, n = nums.length;
        int e = n-1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(s == e){
                return nums[s];
            }
            int currVal = nums[mid];
            int prevVal = -1;
            if(mid - 1 >= 0){
                prevVal = nums[mid-1];
            }
            int nxtVal = -1;
            if(mid + 1 < n){
                nxtVal = nums[mid+1];
            }
            if(currVal != prevVal && currVal != nxtVal){
                return currVal;
            }
            else if(currVal != prevVal && currVal == nxtVal){
                int startIndexOfPair = mid;
                if((startIndexOfPair & 1) == 1){
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }
            }
            else if(currVal == prevVal && currVal != nxtVal){
                int endIndexOfPair = mid;
                if((endIndexOfPair & 1) == 1){
                    s = mid + 1;
                }
                else{
                    e = mid - 1;
                }
            }
        }
        return -1;
    }
}