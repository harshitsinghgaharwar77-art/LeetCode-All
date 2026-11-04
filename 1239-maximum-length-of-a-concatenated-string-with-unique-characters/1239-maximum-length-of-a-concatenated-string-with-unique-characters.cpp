
class Solution {
private:
    bool hasDuplicate(string &s1, string &s2){
        int arr[26] = {0};

        for(char &ch: s1){
            if(arr[ch-'a'] > 0){
                return true;
            }
            arr[ch-'a']++;
        }

        for(char &ch : s2){
            if(arr[ch-'a'] > 0){
                return true;
            }
            arr[ch-'a']++;
        }

        return false;
    }

    int solve(int i, vector<string>& arr, string temp, int n){
        if(i >= n) return temp.length();

        int incl = 0, excl = 0;

        // exclude
        excl = solve(i+1, arr, temp, n);

        // include
        if(!hasDuplicate(arr[i], temp)){
            incl = solve(i+1, arr, temp+arr[i], n);
        }

        return max(incl, excl);
    }

public:
    int maxLength(vector<string>& arr) {
        string temp = "";
        int n = arr.size();
        int i = 0;

        return solve(i, arr, temp, n);
    }
};
