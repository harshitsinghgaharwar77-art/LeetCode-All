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
    TreeNode* minNode(TreeNode* root){  // gives the minimum node
        TreeNode* temp = root;
        while(temp -> left != NULL){
            temp = temp -> left;
        }
        return temp;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // base case
        if(root == NULL){
            return NULL;
        }
        if(root -> val == key){
            // 0 child
            if(root -> left == NULL && root -> right == NULL){
                delete root;
                return NULL;
            }
            // 1 child
            // left child
            if(root -> left != NULL && root -> right == NULL){
                TreeNode* temp = root -> left;
                delete root;
                return temp;
            }

            // right child
            if(root -> left == NULL && root -> right != NULL){
                TreeNode* temp = root -> right;
                delete root;
                return temp;
            }
            // 2 child
            if(root -> left != NULL && root -> right != NULL){
                int minVal = minNode(root -> right) -> val;
                root -> val = minVal;
                root -> right = deleteNode(root -> right, minVal);
                return root;
            }
        }
        if(root -> val > key){
            // move to left
            root -> left = deleteNode(root -> left ,key);
            return root;
        }
        else{
            // move to right
            root -> right = deleteNode(root -> right, key);
            return root;
        }
    }
};