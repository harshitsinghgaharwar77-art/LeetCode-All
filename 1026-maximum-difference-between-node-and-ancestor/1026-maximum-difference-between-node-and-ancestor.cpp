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
    int ans = 0;
    void solve(TreeNode* root, int maxi, int mini){
        // base case
        if(root == NULL) return;
        ans = max(ans, max(abs(root -> val -maxi), abs(root -> val - mini)));
        // update maxi and mini
        maxi = max(maxi, root -> val);
        mini = min(mini, root -> val);

        solve(root -> left, maxi, mini);
        solve(root -> right, maxi, mini);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        ans = 0;
        solve(root, root -> val, root -> val);
        return ans;
    }
};