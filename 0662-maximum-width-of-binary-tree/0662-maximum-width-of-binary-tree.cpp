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
    int widthOfBinaryTree(TreeNode* root) {

        if(root == nullptr) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;

        q.push({root, 0});

        unsigned long long ans = 0;

        while(!q.empty()) {

            int size = q.size();

            unsigned long long minIndex = q.front().second;
            unsigned long long first = 0, last = 0;

            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front().first;
                unsigned long long index = q.front().second - minIndex;

                q.pop();

                if(i == 0) first = index;
                if(i == size - 1) last = index;

                if(node->left != nullptr) {
                    q.push({node->left, 2 * index});
                }

                if(node->right != nullptr) {
                    q.push({node->right, 2 * index + 1});
                }
            }

            ans = max(ans, last - first + 1);
        }

        return (int)ans;
    }
};