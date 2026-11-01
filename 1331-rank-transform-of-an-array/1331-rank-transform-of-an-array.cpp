class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        // copy original array
        vector<int> temp = arr;
        // map to store element and its rank
        unordered_map<int, int> mpp;
        // sort the copied array
        sort(temp.begin(), temp.end());
        int rank = 1;
        for(int num : temp){
            if(mpp.find(num) == mpp.end()){
                mpp[num] = rank;
                rank++;
            }
        }
        // replace original elements with their ranks
        for(int i = 0; i < n; i++){
            arr[i] = mpp[arr[i]];
        }
        return arr;
    }
};