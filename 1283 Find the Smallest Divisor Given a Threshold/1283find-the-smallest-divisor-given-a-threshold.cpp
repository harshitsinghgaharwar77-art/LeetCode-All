class Solution {
private:
    bool isValid(vector<int>& nums, int threshold, int mid){
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += ceil((double)nums[i] / mid);
        }
        return sum <= threshold;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = -1;
        if(n > threshold){
            return -1;
        }
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
        }
        int s = 1, e = maxi;
        int ans = -1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(isValid(nums, threshold, mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};