class Solution {
public:
    int totalMoney(int n) {
        int ans = 0, day = 1;
        for(int i = 0; i < n; i++){
            ans += day + (i%7);
            if(i%7 == 6) day++;
        }
        return ans;
    }
};