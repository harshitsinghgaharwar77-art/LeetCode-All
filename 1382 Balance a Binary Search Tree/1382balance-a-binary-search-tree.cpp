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

    // Step 1: Get inorder traversal (sorted)
    void inorder(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    // Step 2: Build Balanced BST from sorted array
    TreeNode* buildBalancedBST(vector<int>& arr, int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(arr[mid]);

        root->left = buildBalancedBST(arr, start, mid - 1);
        root->right = buildBalancedBST(arr, mid + 1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);  // Step 1: flatten into sorted array
        return buildBalancedBST(arr, 0, arr.size() - 1); // Step 2
    }
};
