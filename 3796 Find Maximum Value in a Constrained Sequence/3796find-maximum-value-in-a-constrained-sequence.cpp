class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        auto arr = restrictions;
        long long num = 1e18;
        vector<long long> arr2(n,num);

        arr2[0] = 0;

        for(int i = 0; i < restrictions.size(); i++){
            int idx = restrictions[i][0];
            int val = restrictions[i][1];
            arr2[idx] = min(arr2[idx],(long long)val);
        }

        for(int i = 1; i < n; i++){
            arr2[i] = min(arr2[i], arr2[i-1] + diff[i-1]);
        }

        for(int i = n-2; i >= 0; i--){
            arr2[i] = min(arr2[i], arr2[i+1]+diff[i]);
        }

        long long x = 0, y = 0;

        for(int i = 1; i < n; i++){
            x = min(arr2[i], x+diff[i-1]);
            y = max(x,y);
        }
        return (int)y;
    }
};