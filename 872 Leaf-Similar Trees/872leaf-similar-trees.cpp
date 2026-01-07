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
    void inorder(TreeNode* root, vector<int>& ans)
    {
        // base case
        if(root == NULL)
        {
            return;
        }

        // leaf node
        if(root -> left == NULL && root -> right == NULL)
        {
            ans.push_back(root -> val);
            return;
        }
        
        // recursive call
        inorder(root -> left, ans);
        inorder(root -> right, ans);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;

        inorder(root1,ans1);
        inorder(root2,ans2);

        return ans1 == ans2;
    }
};