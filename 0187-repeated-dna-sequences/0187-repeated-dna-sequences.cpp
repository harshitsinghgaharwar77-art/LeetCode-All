class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        if(s.size() < 10) return ans;
        unordered_map<string, int> mpp;
        string rep;
        for(int i = 0; i < 10; i++){
            rep.push_back(s[i]);
        }
        mpp[rep]++;
        for(int i = 10; i < s.size(); i++){
            rep.push_back(s[i]);
            rep.erase(0,1);
            mpp[rep]++;
            if(mpp[rep] == 2){
                ans.push_back(rep);
            }
        }
        return ans;
    }
};