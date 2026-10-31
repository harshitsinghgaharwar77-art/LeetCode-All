
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string ans = "";
        string say = countAndSay(n-1);
        // processing
        for(int i = 0; i < say.length(); i++){
            char ch = say[i];
            int cnt = 1;
            while(i + 1 < say.length() && say[i] == say[i+1]){
                cnt++;
                i++;
            }
            ans += to_string(cnt) + string(1,ch);
        }
        return ans;
    }
};
