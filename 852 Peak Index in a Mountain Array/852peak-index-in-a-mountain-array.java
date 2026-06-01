class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int n = arr.length;
        int s = 0;
        int e = n-1;
        int ans = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(arr[mid] < arr[mid+1]){
                // we are in left part
                s = mid + 1;
            }
            else{
                ans = mid;  // possible solution
                e = mid - 1;    // check in left part
            }
        }
        return ans;
    }
}