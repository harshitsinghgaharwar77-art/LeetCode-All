
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*, TreeNode*> parent;

    void inorder(TreeNode* root) {
        if (!root) return;

        if (root->left != NULL)
            parent[root->left] = root;

        inorder(root->left);

        if (root->right != NULL)
            parent[root->right] = root;

        inorder(root->right);
    }

    void BFS(TreeNode* target, int k, vector<int>& res) {
        queue<TreeNode*> q;
        q.push(target);

        unordered_set<TreeNode*> vis;
        vis.insert(target);

        while (!q.empty() && k > 0) {
            int n = q.size();

            while (n--) {
                TreeNode* curr = q.front();
                q.pop();

                // Left
                if (curr->left != NULL && !vis.count(curr->left)) {
                    q.push(curr->left);
                    vis.insert(curr->left);
                }

                // Right
                if (curr->right != NULL && !vis.count(curr->right)) {
                    q.push(curr->right);
                    vis.insert(curr->right);
                }

                // Parent
                if (parent.count(curr) &&
                    !vis.count(parent[curr])) {
                    q.push(parent[curr]);
                    vis.insert(parent[curr]);
                }
            }

            k--;
        }

        while (!q.empty()) {
            res.push_back(q.front()->val);
            q.pop();
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        parent.clear();

        inorder(root);
        BFS(target, k, ans);

        return ans;
    }
};
