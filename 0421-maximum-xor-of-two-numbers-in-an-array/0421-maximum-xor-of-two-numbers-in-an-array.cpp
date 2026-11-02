class TrieNode {
public:
// numbers ko 32 bit mein represent krna hai
// isliye 2 size ka array liya hai (0,1) :)
    TrieNode* children[2];
    TrieNode() {
        children[0] = NULL;
        children[1] = NULL;
    }
};

class Trie {
    public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // insertion into trie
    void insert(int num){
        TrieNode* curr = root;
        for(int i = 30; i >= 0; i--){
            // current bit find karo
            int bit = (num >> i) & 1;
            if(curr -> children[bit] == NULL){
                curr -> children[bit] = new TrieNode();
            }
            curr = curr -> children[bit];
        }
    }

    // find the maximum xor with the given number
    int getMaxXor(int num){
        TrieNode* curr = root;
        int maxXor = 0;
        for(int i = 30; i >= 0; i--){
            // bit nikalo
            int bit = (num >> i) & 1;
            // opposite bit ko bhi nikalo
            int oppositeBit = 1-bit;

            // ab opposite bit ko find karo
            if(curr -> children[oppositeBit] != NULL){
                maxXor |= (1 << i);
                curr = curr->children[oppositeBit];
            }
            else curr = curr->children[bit];
        }
        return maxXor;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        Trie* t = new Trie();

        // trie mien numbers insert karo
        for(int i = 0; i < nums.size(); i++) {
            t->insert(nums[i]);
        }
        int ans = 0;
        // Find maximum XOR
        for(int i = 0; i < nums.size(); i++) {
            ans = max(ans, t->getMaxXor(nums[i]));
        }
        return ans;
    }
};