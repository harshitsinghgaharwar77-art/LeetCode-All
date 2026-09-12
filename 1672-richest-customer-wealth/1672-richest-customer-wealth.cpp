class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum = 0, maxSum = 0;
        for(auto x : accounts){
            for(int i = 0; i < x.size(); i++){
                sum += x[i];
            }
            if(sum > maxSum){
                maxSum = sum;
                sum = 0;
            }else{
                sum = 0;
            }
        }
        return maxSum;
    }
};