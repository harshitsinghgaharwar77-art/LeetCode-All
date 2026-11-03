
class Solution {
private:
    bool solve(vector<int>& nums, vector<int>& bucket, int target, int idx){

        // Base case
        if(idx == nums.size()){
            return true;
        }

        for(int i = 0; i < bucket.size(); i++){

            // check if current element fits the target
            if(bucket[i] + nums[idx] <= target){

                bucket[i] += nums[idx];

                if(solve(nums, bucket, target, idx + 1)){
                    return true;
                }

                // Backtrack
                bucket[i] -= nums[idx];
            }

            // Avoid trying identical empty buckets
            if(bucket[i] == 0) break;
        }

        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum = accumulate(nums.begin(), nums.end(), 0);

        // edge case
        if(sum % k != 0) return false;

        int target = sum / k;

        sort(nums.rbegin(), nums.rend());

        if(nums[0] > target) return false;

        vector<int> bucket(k, 0);

        return solve(nums, bucket, target, 0);
    }
};
