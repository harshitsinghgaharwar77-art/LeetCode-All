
class Solution {
public:
    bool isPossible(vector<int>& nums, int maxOperations, int mid){
        int operations = 0;

        for(int &num : nums){
            operations += (num - 1) / mid;

            if(operations > maxOperations){
                return false;
            }
        }

        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        int ans = high;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(isPossible(nums, maxOperations, mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};
