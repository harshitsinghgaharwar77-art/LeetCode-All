class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n = houses.size(), m = heaters.size();
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for(int h : houses){
            int s = 0, e = heaters.size()-1;
            int rad = INT_MAX;
            while(s <= e){
                int mid = s + (e-s)/2;
                rad = min(rad, abs(h-heaters[mid]));
                if(heaters[mid] < h) s = mid + 1;
                else e = mid - 1;
            }
            ans = max(ans, rad);
        }
        return ans;
    }
};