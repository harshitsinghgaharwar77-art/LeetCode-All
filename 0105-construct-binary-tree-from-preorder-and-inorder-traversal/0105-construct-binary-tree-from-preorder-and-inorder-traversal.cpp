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
    unordered_map<int, int> mpp;
    int preIdx = 0;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd){
        // base case
        if(inStart > inEnd) return NULL;
        // take root from preoredr
        int val = preorder[preIdx++];
        TreeNode* root = new TreeNode(val);
        // build left and right part
        int idx = mpp[val];
        root -> left = solve(preorder, inorder, inStart, idx-1);
        root -> right = solve(preorder, inorder, idx+1, inEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preorder se root banegi then inorder se left aur right ka pata chalkega toh uske liye map use krenge find krne ke liye
        // element -> index
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            mpp[inorder[i]] = i;
        }
        return solve(preorder, inorder, 0, n-1);
    }
};