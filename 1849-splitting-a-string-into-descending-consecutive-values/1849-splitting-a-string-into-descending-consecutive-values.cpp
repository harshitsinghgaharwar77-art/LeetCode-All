
class Solution {
private:
    bool solve(string s, unsigned long long parent, bool first, int cnt){
        int n = s.size();

        if(n == 0) return cnt >= 2;

        unsigned long long curr = 0;

        for(int i = 0; i < n; i++){
            curr = curr * 10 + s[i] - '0';

            if(first || parent - curr == 1){
                if(solve(s.substr(i+1), curr, false, cnt+1)){
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool splitString(string s) {
        return solve(s, 0, true, 0);
    }
};
