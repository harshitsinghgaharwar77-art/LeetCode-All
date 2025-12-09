class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        TreeNode* temp = root;

        while (temp != nullptr) {

            if (temp->val == val)
                return temp;

            else if (val < temp->val)
                temp = temp->left;

            else
                temp = temp->right;
        }

        return nullptr;
    }
};
