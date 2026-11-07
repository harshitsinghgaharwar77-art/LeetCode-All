class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
        for(char &ch: s) mpp[ch]++;
        priority_queue<pair<int,int>> pq;
        for(auto &it : mpp) pq.push({it.second, it.first});
        string ans = "";
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans += string(it.first, it.second);
        }
        return ans;
    }
};