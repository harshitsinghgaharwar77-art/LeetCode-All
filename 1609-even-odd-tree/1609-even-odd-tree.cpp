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
    bool isEvenOddTree(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int n = q.size();
            int prev = ((level & 1) == 0) ? 0 : INT_MAX;
            for(int i = 0; i < n; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                int data = frontNode -> val;
                if((level & 1) == 0){
                    // even level odd value, strictly increasing
                    if(((data & 1) == 0) || data <= prev){
                        return false;
                    }
                }
                else{
                    // odd level value, strictly decreasing
                    if(((data & 1) != 0) || data >= prev){
                        return false;
                    }
                }
                prev = data;
                if(frontNode -> left != nullptr){
                    q.push(frontNode -> left);
                }
                if(frontNode -> right != nullptr){
                    q.push(frontNode -> right);
                }
            }
            level++;
        }
        return true;
    }
};