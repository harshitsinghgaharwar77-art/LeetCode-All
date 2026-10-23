class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit, int sum = 0) {
        if (root == nullptr) return nullptr;
        sum += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            return sum < limit ? nullptr : root;
        }
        root->left = sufficientSubset(root->left, limit, sum);
        root->right = sufficientSubset(root->right, limit, sum);
        // If both children are removed, this node is insufficient too.
        if (root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }
        return root;
    }
};