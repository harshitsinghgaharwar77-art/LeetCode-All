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
    int getHeight(TreeNode* root){
        if(root == nullptr) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
public:
    bool isBalanced(TreeNode* root) {
        // base case
        if(root == NULL) return true;
        bool leftAns = isBalanced(root -> left);
        bool rightAns = isBalanced(root -> right);
        int leftheight = getHeight(root -> left);
        int rightheight = getHeight(root -> right);
        bool cond = abs(rightheight-leftheight) <= 1;
        return (leftAns && rightAns && cond);
    }
};