class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int maxScore = 0;
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int i = 0, j = n-1;
        while(i <= j){
            if(power >= tokens[i]){
                power -= tokens[i];
                i++;
                score++;
                maxScore = max(maxScore, score);
            }
            else if(score > 0){
                power += tokens[j]; // sabse badi wali power lenge
                score--;
                j--;
            }
            else return maxScore;
        }
        return maxScore;
    }
};