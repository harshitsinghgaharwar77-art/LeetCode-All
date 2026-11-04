class Solution {
private:
    bool isPossible(string s, string p, vector<int>& removable, int mid){
        int n = s.size(), m = p.size();
        vector<bool> removed(n,false);
        for(int i = 0; i < mid; i++) removed[removable[i]] = true;
        int i = 0, j = 0;
        while(i < n && j < m){
            if(!removed[i] && s[i] == p[j]){
                j++;
            }
            i++;
        }
        return j == m;
    }
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = removable.size();
        int low = 0, high = n, ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossible(s, p, removable, mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return ans;
    }
};