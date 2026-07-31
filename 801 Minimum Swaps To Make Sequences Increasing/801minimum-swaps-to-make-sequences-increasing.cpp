class Solution {
private:
    // Recursive solution
    int solveRec(vector<int>& nums1, vector<int>& nums2, int idx,
                 bool swapped) {
        // base case
        if (idx == nums1.size()) {
            return 0;
        }
        int ans = INT_MAX;
        int prev1 = nums1[idx - 1];
        int prev2 = nums2[idx - 1];

        // catch
        if (swapped) {
            swap(prev1, prev2);
        }

        // no swap case
        if (nums1[idx] > prev1 && nums2[idx] > prev2) {
            ans = solveRec(nums1, nums2, idx + 1, 0);
        }

        // swap case
        if (nums1[idx] > prev2 && nums2[idx] > prev1) {
            ans = min(ans, 1 + solveRec(nums1, nums2, idx + 1, 1));
        }
        return ans;
    }

    // Top down approach
    int solveMem(vector<int>& nums1, vector<int>& nums2, int idx, bool swapped,
                 vector<vector<int>>& dp) {
        // base case
        if (idx == nums1.size()) {
            return 0;
        }

        if (dp[idx][swapped] != -1) {
            return dp[idx][swapped];
        }
        int ans = INT_MAX;
        int prev1 = nums1[idx - 1];
        int prev2 = nums2[idx - 1];

        // catch
        if (swapped) {
            swap(prev1, prev2);
        }

        // no swap case
        if (nums1[idx] > prev1 && nums2[idx] > prev2) {
            ans = solveMem(nums1, nums2, idx + 1, 0, dp);
        }

        // swap case
        if (nums1[idx] > prev2 && nums2[idx] > prev1) {
            ans = min(ans, 1 + solveMem(nums1, nums2, idx + 1, 1, dp));
        }
        return dp[idx][swapped] = ans;
    }

    // Tabulation method
    int solveTab(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for (int idx = n - 1; idx >= 1; idx--) {
            for (int swapped = 1; swapped >= 0; swapped--) {
                int ans = INT_MAX;
                int prev1 = nums1[idx - 1];
                int prev2 = nums2[idx - 1];

                // catch
                if (swapped) {
                    swap(prev1, prev2);
                }

                // no swap case
                if (nums1[idx] > prev1 && nums2[idx] > prev2) {
                    ans = dp[idx + 1][0];
                }

                // swap case
                if (nums1[idx] > prev2 && nums2[idx] > prev1) {
                    ans = min(ans, 1 + dp[idx + 1][1]);
                }
                dp[idx][swapped] = ans;
            }
        }
        return dp[1][0];
    }

    // Space optimised solution
    int solve(vector<int>& nums1, vector<int>& nums2){
        int n = nums1.size();
        int swap = 0;
        int noSwap =0;

        int currSwap = 0;
        int currNoSwap =0;

        for (int idx = n - 1; idx >= 1; idx--) {
            for (int swapped = 1; swapped >= 0; swapped--) {
                int ans = INT_MAX;
                int prev1 = nums1[idx - 1];
                int prev2 = nums2[idx - 1];

                // catch
                if (swapped) {
                    int temp = prev2;
                    prev2 = prev1;
                    prev1 = temp;
                }

                // no swap case
                if (nums1[idx] > prev1 && nums2[idx] > prev2) {
                    ans = noSwap;
                }

                // swap case
                if (nums1[idx] > prev2 && nums2[idx] > prev1) {
                    ans = min(ans, 1 + swap);
                }
                if(swapped)
                    currSwap = ans;
                else
                    currNoSwap = ans;
            }
            swap = currSwap;
            noSwap = currNoSwap;
        }
        return min(swap, noSwap);
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        // it means that the previous index were swapped or not
        bool swapped = 0;
        int n = nums1.size();
        // return solveRec(nums1, nums2, 1, swapped);

        vector<vector<int>> dp(n, vector<int>(2, -1));
        //return solveMem(nums1, nums2, 1, swapped, dp);

        // return solveTab(nums1, nums2);

        return solve(nums1, nums2);
    }
};