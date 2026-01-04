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
    vector<TreeNode *> build(int s, int e)
        {
            vector<TreeNode *> ans;

            // base case
            if (s > e)
            {
                ans.push_back(nullptr);
                return ans;
            }

            for (int i = s; i <= e; i++)
            {
                vector<TreeNode *> left_tree = build(s, i - 1);
                vector<TreeNode *> right_tree = build(i + 1, e);

                for (auto left : left_tree)
                {
                    for (auto right : right_tree)
                    {
                        TreeNode *node = new TreeNode(i);
                        node->left = left;
                        node->right = right;
                        ans.push_back(node);
                    }
                }
            }
            return ans;
        }
public:
    vector<TreeNode*> generateTrees(int n) {
       // base case
       if(n == 0)
       {
        return {};
       }
       return build(1,n);
    }
};