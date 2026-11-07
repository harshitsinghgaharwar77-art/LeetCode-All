class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        for(auto s : words) mpp[s]++;
        // store {word, freq}
        //Sort using: Higher frequency first. If frequency is equal, lexicographically smaller word first.
        // return k elemenets
        vector<pair<int,string>> a;
        for(auto &it : mpp){
            a.push_back({it.second, it.first});
        }
        sort(a.begin(), a.end(), [](auto &a, auto &b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first > b.first;
        });
        vector<string> ans;
        for(int i = 0; i < k; i++) ans.push_back(a[i].second);
        return ans;
    }
};