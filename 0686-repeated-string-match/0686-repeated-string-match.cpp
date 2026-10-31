class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.length(), m = b.length(), cnt=0;
        string repeated = "";
        while(repeated.length() < m){
            repeated += a;
            cnt++;
        }
        if(repeated.find(b) != string::npos) return cnt;
        repeated += a;
        cnt++;
        if(repeated.find(b) != string::npos) return cnt;
        return -1;
    }
};