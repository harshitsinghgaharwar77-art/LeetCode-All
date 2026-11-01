class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = INT_MIN;
        for(auto &it : sentences){
            int cnt = 1;
            for(char ch : it){
                if(ch == ' ') cnt++;
            }
            if(cnt > maxi) maxi = cnt;
        }
        return maxi;
    }
};