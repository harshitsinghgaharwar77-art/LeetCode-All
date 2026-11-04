class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> temp;
        for(int i = 0; i < words.size(); i++) if(words[i].find(x) != string::npos)temp.push_back(i);
        return temp;
    }
};