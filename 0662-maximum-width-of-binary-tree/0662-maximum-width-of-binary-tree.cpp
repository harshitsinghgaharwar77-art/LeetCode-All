
class Solution {
public:
    typedef unsigned long long ll;

    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;

        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});

        ll maxWidth = 0;

        while (!q.empty()) {
            ll l = q.front().second;
            ll r = q.back().second;

            maxWidth = max(maxWidth, r - l + 1);

            ll n = q.size();

            while (n--) {
                TreeNode* frontNode = q.front().first;
                ll idx = q.front().second;
                q.pop();

                // Normalize indices to avoid overflow
                idx -= l;

                if (frontNode->left != NULL) {
                    q.push({frontNode->left, 2 * idx + 1});
                }

                if (frontNode->right != NULL) {
                    q.push({frontNode->right, 2 * idx + 2});
                }
            }
        }

        return (int)maxWidth;
    }
};
