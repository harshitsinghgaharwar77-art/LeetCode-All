class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        TreeNode* current = root;

        while (current != NULL) {

            // If left child doesn't exist
            if (current->left == NULL) {
                ans.push_back(current->val);
                current = current->right;
            }

            else {

                // Find inorder predecessor
                TreeNode* predecessor = current->left;

                while (predecessor->right != NULL &&
                       predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                // Thread doesn't exist
                if (predecessor->right == NULL) {
                    predecessor->right = current;
                    current = current->left;
                }

                // Thread already exists
                else {
                    predecessor->right = NULL;
                    ans.push_back(current->val);
                    current = current->right;
                }
            }
        }

        return ans;
    }
};