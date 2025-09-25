class Solution {
public:
    string reversePrefix(string word, char ch) {
        // Find index of first occurrence of ch
        int idx = word.find(ch);
        
        // If ch not found, return the original word
        if (idx == string::npos) return word;
        
        // Reverse substring from 0 to idx
        reverse(word.begin(), word.begin() + idx + 1);
        
        return word;
    }
};
