class Solution {
private:
    vector<int> solveFast(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3){
        vector<int> mask(101, 0);

        for(int x : nums1) mask[x] |= 1;
        for(int x : nums2) mask[x] |= 2;
        for(int x : nums3) mask[x] |= 4;

        vector<int> ans;

        for(int i = 1; i <= 100; i++){
            if(__builtin_popcount(mask[i]) >= 2){
                ans.push_back(i);
            }
        }

        return ans;
    }

public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> freq(101,0);
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        unordered_set<int> s3(nums3.begin(), nums3.end());
        for(auto it : s1) freq[it]++;
        for(auto it : s2) freq[it]++;
        for(auto it : s3) freq[it]++;
        vector<int> ans;
        for(int i = 1; i <= 100; i++){
            if(freq[i] >= 2){
                ans.push_back(i);
            }
        }
        return ans;
        // return solveFast(nums1, nums2, nums3);
    }
};