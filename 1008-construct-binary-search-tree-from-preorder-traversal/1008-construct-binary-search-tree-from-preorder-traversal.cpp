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
    int preIdx;
    TreeNode* solve(vector<int>& preorder, int bound){
        // base case
        if(preIdx >= preorder.size() || preorder[preIdx] > bound){
            return nullptr;
        }
        // construct root
        int val = preorder[preIdx++];
        TreeNode* root = new TreeNode(val);
        // build left and right part of BST
        // left part mein chote elemnt honge root se
        root -> left = solve(preorder, root -> val);
        // right part mein bade element hinge root se
        root -> right = solve(preorder, bound);

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        preIdx = 0;
        return solve(preorder, INT_MAX);
    }
};