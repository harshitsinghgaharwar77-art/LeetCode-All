/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int solve(TreeNode* root, int& maxSum) {
        if (root == nullptr)
            return 0;

        int leftGain = max(0, solve(root->left, maxSum));
        int rightGain = max(0, solve(root->right, maxSum));

        int currentPath = root->val + leftGain + rightGain;

        maxSum = max(maxSum, currentPath);

        return root->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;

        solve(root, maxSum);

        return maxSum;
    }
};