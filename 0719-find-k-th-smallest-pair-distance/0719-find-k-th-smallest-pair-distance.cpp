
class Solution {
public:
    int slidingWindowCnt(vector<int> &nums, int d){
        int i = 0, j = 1, n = nums.size(), pairCnt = 0;
        while(j < n){
            while(nums[j] - nums[i] > d){
                i++;
            }
            pairCnt += (j-i);
            j++;
        }
        return pairCnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0, r = nums[n-1] - nums[0];
        int ans = 0;

        while(l <= r){
            int mid = l + (r-l)/2;
            int cntPair = slidingWindowCnt(nums, mid);

            if(cntPair < k) l = mid + 1;
            else{
                ans = mid;
                r = mid - 1;
            }
        }
        return ans;
    }
};
