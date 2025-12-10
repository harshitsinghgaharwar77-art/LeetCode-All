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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
    
    TreeNode* build(vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;

        // middle element os the root node
        int mid = left + (right - left) / 2;
        // creation of the root
        TreeNode* root = new TreeNode(nums[mid]);

        // creating the left part
        root->left = build(nums, left, mid - 1);

        // creating the right sub part
        root->right = build(nums, mid + 1, right);

        return root;
    }
};
