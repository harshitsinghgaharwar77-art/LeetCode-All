
class Solution {
private:
    bool solve(vector<int>& matchsticks, int target, vector<int>& sides, int idx){
        // base case
        if(idx == matchsticks.size()){
            if(sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3]){
                return true;
            }
            return false;
        }
        for(int i = 0; i < 4; i++){
            if(sides[i] + matchsticks[idx] > target){
                continue;
            }
            int j = i-1;
            while(j >= 0){
                if(sides[j] == sides[i]){
                    break;
                }
                j -= 1;
            }
            if(j != -1) continue;

            sides[i] += matchsticks[idx];
            if(solve(matchsticks, target, sides, idx+1)) return true;
            sides[i] -= matchsticks[idx];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        // edge case
        if(n < 4) return false;
        int sum = 0;
        for(int i = 0; i < n; i++) sum += matchsticks[i];

        if(sum % 4 != 0) return false;

        int target= sum/4;
        vector<int> sides(4,0);
        sort(matchsticks.begin(),matchsticks.end(), greater<int>());

        if(matchsticks[0] > target) return false;

        return solve(matchsticks, target, sides, 0);
    }
};
