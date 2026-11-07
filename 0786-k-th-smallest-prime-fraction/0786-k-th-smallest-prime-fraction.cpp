class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        int mini = INT_MAX;
        // {fraction, {numerator idx, denominator idx}}
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;

        for(int x = 1; x < n; x++){
            pq.push({(double)arr[0]/arr[x], {0,x}});
        }

        while(k--){
            auto it = pq.top();
            pq.pop();

            int i = it.second.first;
            int j = it.second.second;

            if(k == 0){
                return {arr[i], arr[j]};
            }

            if(i+1 < j){
                // move to next fraction
                pq.push({(double)arr[i+1]/arr[j], {i+1,j}});
            }
        }
        return {};
    }
};