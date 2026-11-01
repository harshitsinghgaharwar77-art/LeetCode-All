class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size(), fiveCnt = 0, TenCnt = 0;
        for(int i = 0; i < n; i++){
            if(bills[i] == 5) fiveCnt++;
            else if(bills[i] == 10){
                if(fiveCnt >= 1){
                    fiveCnt--;
                    TenCnt++;
                }
                else return false;
            }
            else if(bills[i] == 20){
                if(TenCnt >= 1 && fiveCnt >= 1){
                    TenCnt--;
                    fiveCnt--;
                }
                else if(fiveCnt >= 3){
                    fiveCnt -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};