class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        if(m == 0) return 0;
        // try matching needle at every starting point in haystack
        for(int i = 0; i <= n-m; i++){
            int j = 0;
            while(j < m && haystack[i+j] == needle[j]) j++;
            if(j == m) return i;
        }
        return -1;
    }
};