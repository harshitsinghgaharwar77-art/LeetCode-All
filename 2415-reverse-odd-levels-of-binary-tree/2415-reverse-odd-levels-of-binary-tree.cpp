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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == NULL) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            vector<TreeNode*> nodes;
            for(int i = 0; i < n; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                nodes.push_back(frontNode);
                if(frontNode -> left != NULL){
                    q.push(frontNode -> left);
                }
                if(frontNode -> right != NULL){
                    q.push(frontNode -> right);
                }
            }
            if((level & 1) == 1){
                int left = 0, right = n-1;
                while(left < right){
                    swap(nodes[left]->val, nodes[right]->val);
                    left++;right--;
                }
            }
            level++;
        }
        return root;
    }
};