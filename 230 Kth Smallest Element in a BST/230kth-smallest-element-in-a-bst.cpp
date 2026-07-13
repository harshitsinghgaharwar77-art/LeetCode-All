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
    // inorder traversal of bst is sorted.
    private:
    int solve(TreeNode* root, int &i, int k){
        // base case
        if(root == NULL){
            return -1;
        }
        // L
        int leftAns = solve(root -> left, i, k);
        if(leftAns != -1){
            return leftAns;
        }
        // N
        i++;
        if(i == k){
            return root -> val;
        }
        // R
        return solve(root -> right, i, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        int ans = solve(root, i, k);
        return ans;
    }
};