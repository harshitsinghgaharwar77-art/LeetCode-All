#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        unordered_set<string> final_set = parse(expression, i);
        
        // Convert to vector and sort lexicographically
        vector<string> res(final_set.begin(), final_set.end());
        sort(res.begin(), res.end());
        
        return res;
    }

private:
    unordered_set<string> parse(const string& s, int& i) {
        unordered_set<string> res;
        unordered_set<string> curr_term = {""};
        
        while (i < s.length()) {
            if (s[i] == '{') {
                i++; // Consume '{'
                // Recursively evaluate the sub-expression
                unordered_set<string> sub_set = parse(s, i);
                
                // Cross product (concatenation)
                unordered_set<string> next_term;
                for (const string& prefix : curr_term) {
                    for (const string& suffix : sub_set) {
                        next_term.insert(prefix + suffix);
                    }
                }
                curr_term = next_term;
            } 
            else if (isalpha(s[i])) {
                // Concatenate the character to all prefixes in the current term
                unordered_set<string> next_term;
                for (const string& prefix : curr_term) {
                    next_term.insert(prefix + s[i]);
                }
                curr_term = next_term;
                i++;
            } 
            else if (s[i] == ',') {
                // Current term is fully constructed, merge to the union set 'res'
                res.insert(curr_term.begin(), curr_term.end());
                curr_term = {""}; // Reset for the next term
                i++;
            } 
            else if (s[i] == '}') {
                i++; // Consume '}' and break out of the current nested level
                break;
            }
        }
        
        // Incorporate the last parsed term of the current group
        res.insert(curr_term.begin(), curr_term.end());
        
        return res;
    }
};