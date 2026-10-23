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
    int ans = INT_MIN;
    int solve(TreeNode* root){
        // base case
        if(root == NULL) return 0;
        int leftAns = solve(root -> left);
        int rightAns = solve(root -> right);
        leftAns = max(0,leftAns);
        rightAns = max(0,rightAns);
        ans = max(ans, leftAns + rightAns + root -> val);
        return root -> val + max(rightAns, leftAns);
    }
public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        solve(root);
        return ans;
    }
};