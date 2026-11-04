class Solution {
private:
    bool isPossible(vector<int>& ranks, int cars, long long mid){
        int n = ranks.size();
        long long totalCars = 0;
        for(int i = 0; i < n; i++){
            //A mechanic with a rank r can repair n cars in r * n^2 minutes. isi formulae se aaya hai
            long long repaired = sqrtl((long double)mid / ranks[i]);
            totalCars += repaired;
            if(totalCars >= cars){
                return true;
            }
        }
        return false;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long s = 1;
        long long minRank = *min_element(ranks.begin(), ranks.end());
        //A mechanic with a rank r can repair n cars in r * n^2 minutes.
        long long e = minRank * cars * cars;
        long long ans = -1;
        while(s <= e){
            long long mid = s + (e-s)/2;
            if(isPossible(ranks, cars, mid)){
                ans = mid;
                e = mid - 1;
            }else s = mid + 1;
        }
        return ans;
    }
};