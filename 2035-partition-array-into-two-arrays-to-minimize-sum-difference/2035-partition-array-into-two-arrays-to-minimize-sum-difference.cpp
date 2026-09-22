class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for(int x : nums) {
            totalSum += x;
        }

        int half = n / 2;

        vector<vector<int>> left(half + 1);
        vector<vector<int>> right(half + 1);

        // Generate all subsets of left half
        for(int mask = 0; mask < (1 << half); mask++) {
            int sum = 0;
            int cnt = 0;

            for(int i = 0; i < half; i++) {
                if(mask & (1 << i)) {
                    sum += nums[i];
                    cnt++;
                }
            }

            left[cnt].push_back(sum);
        }

        // Generate all subsets of right half
        for(int mask = 0; mask < (1 << half); mask++) {
            int sum = 0;
            int cnt = 0;

            for(int i = 0; i < half; i++) {
                if(mask & (1 << i)) {
                    sum += nums[i + half];
                    cnt++;
                }
            }

            right[cnt].push_back(sum);
        }

        for(int i = 0; i <= half; i++) {
            sort(right[i].begin(), right[i].end());
        }

        int mini = INT_MAX;

        // Choose i elements from left
        // and half-i elements from right
        for(int cnt = 0; cnt <= half; cnt++) {

            int need = half - cnt;

            for(int sumLeft : left[cnt]) {

                // We want:
                // sumLeft + sumRight ~= totalSum / 2

                double target = (double)totalSum / 2 - sumLeft;

                auto it = lower_bound(
                    right[need].begin(),
                    right[need].end(),
                    target
                );

                // Check current element
                if(it != right[need].end()) {
                    int sum1 = sumLeft + *it;
                    int sum2 = totalSum - sum1;

                    mini = min(mini, abs(sum1 - sum2));
                }

                // Check previous element
                if(it != right[need].begin()) {
                    --it;

                    int sum1 = sumLeft + *it;
                    int sum2 = totalSum - sum1;

                    mini = min(mini, abs(sum1 - sum2));
                }
            }
        }

        return mini;
    }
};