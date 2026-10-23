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
    unordered_map<int,int> mpp;
    int postIdx;
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd){
        // base case
        if(inStart > inEnd) return nullptr;
        int val = postorder[postIdx--];
        // build root node
        TreeNode* root = new TreeNode(val);
        // build left and right part
        int idx = mpp[val];
        root -> right = solve(inorder, postorder, idx+1, inEnd);
        root -> left = solve(inorder, postorder, inStart, idx-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // postorder ke peeche se root ka pata chalega aur inorder mein position ka
        mpp.clear();
        int n = postorder.size();
        for(int i = 0; i < n; i++){
            mpp[inorder[i]] = i;
        }
        postIdx = n-1;
        return solve(inorder, postorder, 0,n-1);
    }
};