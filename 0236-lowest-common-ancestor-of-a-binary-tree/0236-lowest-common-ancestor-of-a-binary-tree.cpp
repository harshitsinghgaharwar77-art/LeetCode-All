
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case
        if (root == nullptr) return nullptr;
        if (root == p || root == q) return root;
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
        if (leftAns == nullptr && rightAns == nullptr) return nullptr;
        else if (leftAns != nullptr && rightAns == nullptr) return leftAns;
        else if (leftAns == nullptr && rightAns != nullptr) return rightAns;
        else return root;
    }
};
