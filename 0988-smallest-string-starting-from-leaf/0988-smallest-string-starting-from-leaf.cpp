
class Solution {
private:
    string ans = "";
    void solve(TreeNode* root, string& path) {
        // Base case
        if (root == nullptr) return;
        // Add current character
        path += char('a' + root->val);
        // If leaf node
        if (root->left == nullptr && root->right == nullptr) {
            string temp = path;
            reverse(temp.begin(), temp.end());
            if (ans == "" || temp < ans) {
                ans = temp;
            }
            path.pop_back();
            return;
        }
        // Recursive calls
        solve(root->left, path);
        solve(root->right, path);
        // Backtrack
        path.pop_back();
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        ans = "";
        string path = "";
        solve(root, path);
        return ans;
    }
};
