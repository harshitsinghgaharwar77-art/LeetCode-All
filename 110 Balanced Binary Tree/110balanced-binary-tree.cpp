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
    int height(TreeNode* root){
        // base case
        if(root == nullptr){
            return -1;
        }
        int leftAns = height(root -> left);
        int rightAns = height(root -> right);
        return 1 + max(leftAns, rightAns);
    }
public:
    bool isBalanced(TreeNode* root) {
        // base case
        if(root == nullptr){
            return true;
        }
        bool leftAns = isBalanced(root -> left);
        bool rightAns = isBalanced(root -> right);
        bool diff = abs(height(root -> left) - height(root -> right)) <= 1;
        if(leftAns && rightAns && diff){
            return true;
        }
        else{
            return false;
        }
    }
};