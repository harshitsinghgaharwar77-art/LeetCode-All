
class Solution {
private:
    void solve(TreeNode* root, int targetSum,
               vector<int>& temp, vector<vector<int>>& ans) {
        // Base case
        if (root == nullptr) return;
        int val = root->val;
        temp.push_back(val);
        targetSum -= val;
        // Check only at leaf nodes
        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == 0) {
                ans.push_back(temp);
            }
            temp.pop_back();
            return;
        }
        solve(root->left, targetSum, temp, ans);
        solve(root->right, targetSum, temp, ans);
        // Backtrack
        temp.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root, targetSum, temp, ans);
        return ans;
    }
};
