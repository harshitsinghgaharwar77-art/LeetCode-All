class Solution {
    private:
    double isValid(vector<int>& dist,int mid){
        double time = 0.0;
        int n = dist.size();
        for(int i = 0; i < n-1; i++){
            double t = (double)dist[i]/(double)mid;
            time += ceil(t);
        }
        time += (double)dist[n-1]/(double)mid;
        return time;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        int l = 1, r = 1e7, ans = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(isValid(dist,mid) <= hour){
                ans = mid;
                r = mid - 1;
            }else l = mid + 1;
        }
        return ans;
    }
};