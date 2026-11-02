class TrieNode{
    public:
        TrieNode* children[2];

        TrieNode(){
            children[0] = NULL;
            children[1] = NULL;
        }
};

class Trie{
    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode();
        }

        void insert(int x, TrieNode* root){
            for(int i = 31; i >= 0; i--){
                int bit = ((x >> i) & 1);

                if(root->children[bit] == NULL){
                    root->children[bit] = new TrieNode();
                }

                root = root->children[bit];
            }
        }

        int find(int x, TrieNode* root){
            int ret = 0;

            for(int i = 31; i >= 0; i--){
                int bit = ((x >> i) & 1);

                if(root->children[bit ^ 1] == NULL){
                    root = root->children[bit];
                }
                else{
                    ret = ret | (1 << i);
                    root = root->children[bit ^ 1];
                }
            }

            return ret;
        }
};

class Solution {
public:

    static bool cmp(vector<int> &v1, vector<int>& v2){
        return v1[1] < v2[1];
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        Trie* t = new Trie();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < queries.size(); i++){
            queries[i].push_back(i);
        }

        sort(queries.begin(), queries.end(), cmp);

        int i = 0;
        vector<int> ans(queries.size());

        for(auto a : queries){

            for(; i < nums.size(); i++){
                if(nums[i] > a[1]) break;

                t->insert(nums[i], t->root);
            }

            if(i == 0)
                ans[a[2]] = -1;
            else
                ans[a[2]] = t->find(a[0], t->root);
        }

        return ans;
    }
};