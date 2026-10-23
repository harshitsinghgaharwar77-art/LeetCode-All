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
    void solve(TreeNode* root, string path, vector<string> &ans){
        if(root == nullptr) return;
        // add current  node to path
        path += to_string(root->val);
        // check leaf node
        if(root -> left == NULL && root -> right == NULL){
            ans.push_back(path);
            return;
        }
        // baaki paths ko dekho
        path += "->";
        solve(root -> left, path, ans);
        solve(root -> right, path, ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root, "", ans);
        return ans;
    }
};