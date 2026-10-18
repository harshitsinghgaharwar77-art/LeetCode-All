class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // algo
        // 1. when new element comes nums[i], make the space for it (window size can't be greater than k)

        // 2. Now, when nums[i] comes, there is no need to keep small elements in that window, pop them

        // 3. Now push i in deque -> for nums[i]

        // 4. If (i >= k-1) then deq.front() is our answer for that window

        int n =nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            // step-1: make space for nums[i]
            while(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            // step-2: 
            // < for smaller*
            while(!dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            // step-3:
            dq.push_back(i);
            //step-4:
            if(i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};