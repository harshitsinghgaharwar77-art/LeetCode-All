class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // approach 1 : use hashmap
        // approach 2 : sort the array and check
        // approach 3 : bit manipulation
        int res = 0;
        for(int i = 0; i <= 31; i++){
            int ones = 0, temp = (1 << i);
            for(int num : nums){
                if((num & temp) != 0) ones++;
            }
            if(ones % 3 == 1) res = (res | temp);
        }
        return res;
    }
};