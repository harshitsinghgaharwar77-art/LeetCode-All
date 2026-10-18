class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), j = 0, i = 0, cnt = 0;
        unordered_map<int,int> mpp;
        while(j < n){
            mpp[fruits[j]]++;
            if(mpp.size() <= 2){
                cnt = max(cnt,j-i+1);
            }else{
                mpp[fruits[i]]--;
                if(mpp[fruits[i]] == 0){
                    mpp.erase(fruits[i]);
                }
                i++;
            }
            j++;
        }
        return cnt;
    }
};