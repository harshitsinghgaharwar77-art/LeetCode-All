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
    void createMapping(vector<int>& inorder, map<int, int>& nodeToIndex, int n) {
        for (int i = 0; i < n; i++) {
            nodeToIndex[inorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                    int& idx, int inorderStart, int inorderEnd,
                    map<int, int>& nodeToIndex) {

        // Base case
        if (idx < 0 || inorderStart > inorderEnd)
            return NULL;

        // Root node
        int element = postorder[idx--];
        TreeNode* root = new TreeNode(element);

        // Position of root in inorder
        int pos = nodeToIndex[element];

        // Build right subtree first
        root->right = solve(inorder, postorder, idx, pos + 1, inorderEnd, nodeToIndex);

        // Build left subtree
        root->left = solve(inorder, postorder, idx, inorderStart, pos - 1, nodeToIndex);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();

        int postOrderIndex = n - 1;   // Start from last element

        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex, n);

        return solve(inorder, postorder, postOrderIndex, 0, n - 1, nodeToIndex);
    }
};