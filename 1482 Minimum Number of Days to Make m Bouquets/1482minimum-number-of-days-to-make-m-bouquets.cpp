class Solution {
private:
    bool isValid(vector<int>& bloomDay, int m, int k, int maxDay){
        int bouquet = 0, cnt = 0;
        int n = bloomDay.size();
        for(int i = 0; i < n; i++){
            if(bloomDay[i] <= maxDay){
                cnt++;
                if(cnt == k){
                    bouquet++;
                    cnt = 0;
                    if(bouquet == m){
                        return true;
                    }
                }
            }
            else{
                cnt = 0;
            }
        }
        return false;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), ans = -1, maxi = -1;
        for(int i = 0; i < n; i++){
            if(maxi < bloomDay[i]){
                maxi = bloomDay[i];
            }
        }
        if((long long)m * k > n){
            return -1;
        }
        int s = 1, e = maxi;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(isValid(bloomDay, m, k, mid)){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};