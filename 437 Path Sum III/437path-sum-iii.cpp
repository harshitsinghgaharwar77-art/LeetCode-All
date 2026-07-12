/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    void solve(TreeNode* root, long long currSum, int targetSum,
               unordered_map<long long, int>& mp, int &cnt) {

        if (root == nullptr)
            return;

        currSum += root->val;

        cnt += mp[currSum - targetSum];

        mp[currSum]++;

        solve(root->left, currSum, targetSum, mp, cnt);
        solve(root->right, currSum, targetSum, mp, cnt);

        mp[currSum]--;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> mp;
        mp[0] = 1;

        int cnt = 0;
        solve(root, 0, targetSum, mp, cnt);

        return cnt;
    }
};