
class Solution {
    unordered_map<int, int> mpp;
    int maxD = 0;
    void depth(TreeNode* root, int d) {
        if (root == nullptr) return;
        mpp[root->val] = d;
        maxD = max(maxD, d);
        depth(root->left, d + 1);
        depth(root->right, d + 1);
    }
    TreeNode* LCA(TreeNode* root) {
        if (root == nullptr || mpp[root->val] == maxD) {
            return root;
        }
        TreeNode* l = LCA(root->left);
        TreeNode* r = LCA(root->right);
        if (l && r) return root;
        return l != nullptr ? l : r;
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        mpp.clear();
        maxD = 0;
        depth(root, 0);
        return LCA(root);
    }
};
