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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            // add new node
            TreeNode* node = new TreeNode(val);
            node -> left = root;
            return node;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(!q.empty() && level < depth-1){
            int n = q.size();
            for(int i = 0; i < n; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                if(frontNode -> left != NULL){
                    q.push(frontNode -> left);
                }
                if(frontNode -> right){
                    q.push(frontNode -> right);
                }
            }
            level++;
        }
        while(!q.empty()){
            // yahan pe new nodes insert krni hain
            TreeNode* frontNode = q.front();
            q.pop();
            TreeNode* newLeftNode = new TreeNode(val);
            TreeNode* newRightNode = new TreeNode(val);
            newLeftNode -> left = frontNode -> left;
            newRightNode -> right = frontNode -> right;
            frontNode->left = newLeftNode;
            frontNode->right = newRightNode;
        }
        return root;
    }
};