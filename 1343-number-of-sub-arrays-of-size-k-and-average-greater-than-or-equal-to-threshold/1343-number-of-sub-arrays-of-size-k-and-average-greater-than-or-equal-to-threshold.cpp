class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int a = 0, sum = 0, cnt = 0;
        for(int i = 0; i < k; i++){
            sum += arr[i];
        }
        a = sum/k;
        if(a >= threshold) cnt++;
        for(int i = k; i < n; i++){
            sum += arr[i];
            sum -= arr[i-k];
            a = sum/k;
            if(a >= threshold){
                cnt++;
            }
        }
        return cnt;
    }
};