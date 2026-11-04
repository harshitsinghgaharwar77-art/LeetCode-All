class Solution {
private:
    int isPossible(int mid, int m, int n){
        int sum = 0;
        for(int i = 1; i <= m; i++) sum += min(mid/i,n);
        return sum;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int s = 0, e = m*n;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(isPossible(mid,m,n) < k) s = mid + 1;
            else e = mid - 1;
        }
        return s;
    }
};