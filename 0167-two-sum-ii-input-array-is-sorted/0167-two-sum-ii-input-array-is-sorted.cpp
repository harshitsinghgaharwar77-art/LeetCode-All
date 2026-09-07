class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> mpp;

        for(int i = 0; i < numbers.size(); i++) {
            int num = numbers[i];

            int moreRequired = target - num;

            // Is the required number already present?
            if(mpp.find(moreRequired) != mpp.end()) {
                return {mpp[moreRequired]+1, i+1};
            }

            // Store current number and its index
            mpp[num] = i;
        }

        return {-1, -1};
    }
};