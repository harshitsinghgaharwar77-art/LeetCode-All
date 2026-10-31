class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int maxScore = 0, score = 0;
        sort(tokens.begin(),tokens.end());
        int i = 0, j = n-1;
        while(i <= j){
            if(power >= tokens[i]){
                // play faceup
                power -= tokens[i];
                score++;
                i++;
                maxScore = max(maxScore, score);
            }
            else if(score > 0 && i < j){
                // play facedown
                power += tokens[j];
                score--;
                j--;
            }
            else break;
        }
        return maxScore;
    }
};