class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefixXor(n+1,0);
        vector<int> ans;
        // use prefixXor
        for(int i = 0; i < n; i++){
            prefixXor[i+1] = prefixXor[i] ^ arr[i];
        }
        for(auto i : queries){
            int start = i[0], end = i[1];
            ans.push_back(prefixXor[end+1] ^ prefixXor[start]);
        }
        return ans;
    }
};