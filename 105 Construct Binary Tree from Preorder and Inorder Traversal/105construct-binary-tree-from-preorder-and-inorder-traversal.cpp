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
    void createMapping(map<int, int> &nodeToIdx, vector<int> &inorder, int n) {
        for (int i = 0; i < n; i++) {
            nodeToIdx[inorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int> &preorder,
                    vector<int> &inorder,
                    int &preorderIdx,   // Pass by reference
                    int inorderStart,
                    int inorderEnd,
                    map<int, int> &nodeToIdx,
                    int n) {

        // Base case
        if (preorderIdx >= n || inorderStart > inorderEnd)
            return NULL;

        int elem = preorder[preorderIdx++];
        TreeNode *root = new TreeNode(elem);

        int pos = nodeToIdx[elem];

        root->left = solve(preorder, inorder, preorderIdx,
                           inorderStart, pos - 1,
                           nodeToIdx, n);

        root->right = solve(preorder, inorder, preorderIdx,
                            pos + 1, inorderEnd,
                            nodeToIdx, n);

        return root;
    }

public:
    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();

        map<int, int> nodeToIdx;
        createMapping(nodeToIdx, inorder, n);

        int preorderIdx = 0;

        return solve(preorder, inorder, preorderIdx,
                     0, n - 1, nodeToIdx, n);
    }
};