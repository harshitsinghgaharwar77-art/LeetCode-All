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
public:
    int minDepth(TreeNode* root) {
        // base case
        if(root == nullptr) return 0;
        int left = minDepth(root -> left);
        int right = minDepth(root -> right);
        // if left child is absent
        if(root -> left == NULL) return 1 + right;
        // if right child is absent
        if(root -> right == NULL) return 1 + left;
        return 1 + min(left, right);
    }
};