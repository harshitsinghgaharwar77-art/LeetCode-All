class Solution {
private:
    int solve(vector<int> &freq){
        int cnt =0 ;
        for(int i = 0; i < 26; i++){
            // check if character is available
            if(freq[i] > 0){
                // character ko include karo
                cnt++;
                // character ki freq ko decrement karo
                freq[i]--;
                // aage ke liye recursive call mar do
                cnt += solve(freq);
                // backtrack krlo
                freq[i]++;
            }
        }
        return cnt;
    }
public:
    int numTilePossibilities(string tiles) {
        vector<int> freq(26,0);
        for(char ch : tiles) freq[ch-'A']++;
        return solve(freq);
    }
};