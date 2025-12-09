/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* buildBST(vector<int>& preorder, int& i, int bound) {
        if (i == preorder.size() || preorder[i] > bound)
            return NULL;

        TreeNode* root = new TreeNode(preorder[i]);
        i++;

        root->left = buildBST(preorder, i, root->val);  // left subtree
        root->right = buildBST(preorder, i, bound);     // right subtree

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return buildBST(preorder, i, INT_MAX);
    }
};
