/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    bool solve(TreeNode* root, int k, unordered_set<int> &s){
        // base case
        if(root == nullptr) return false;
        // check if k-root->val exixtes in set
        if(s.count(k - root -> val)) return true;
        // if not existed then insert it
        s.insert(root -> val);
        // recursive calls
        return solve(root -> left, k, s) || solve(root -> right, k, s);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        // use the same approach for two sum by unordered map
        unordered_set<int> s;
        return solve(root, k, s);
    }
};