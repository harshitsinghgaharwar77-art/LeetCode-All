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
    private:
    // check whether the final tree is a valid BST or not
    bool checkBST(TreeNode* root, long long mini, long long maxi, unordered_set<int>& leaves){
        if(root == nullptr) return true;
        if(root -> val <= mini || root -> val >= maxi) return false;
        // if this is a leaf, remove it from the leaf set
        if(root -> left == nullptr && root -> right == nullptr) leaves.erase(root -> val);
        return checkBST(root -> left, mini, root -> val, leaves) && checkBST(root -> right, root -> val, maxi, leaves);
    }

public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> leaves;

        // store every root
        for(TreeNode* root : trees){
            mp[root -> val] = root;
        }

        // store leaf values
        for(TreeNode* root : trees){
            if(root -> left) leaves.insert(root -> left -> val);
            if(root -> right) leaves.insert(root -> right -> val);
        }

        // find the root which is not a leaf of any other tree
        TreeNode* root = nullptr;
        for(TreeNode* node : trees){
            if(leaves.find(node -> val) == leaves.end()){
                if(root != nullptr){
                    return nullptr;
                }
                root = node;
            }
        }

        if(root == nullptr) return nullptr;

        // merge trees using DFS
        function<void(TreeNode*)> merge = [&](TreeNode* node){
            if(node == nullptr) return ;

            // if current node is a leaf and another tree has
            // this value as its root, attach that tree
            if(node -> left == nullptr && node -> right == nullptr){
                if(mp.find(node -> val) != mp.end() && mp[node -> val] != node){
                    TreeNode* other = mp[node -> val];
                    node -> left = other -> left;
                    node -> right = other -> right;

                    // remove it as it not used again
                    mp.erase(node -> val);
                }
            }

            merge(node -> left);
            merge(node -> right);
        };

        merge(root);

        // everytime tree must have been merged
        if(mp.size() != 1) return nullptr;

        // validate BST
        unordered_set<int> remainingLeaves = leaves;
        if(!checkBST(root, LLONG_MIN, LLONG_MAX, remainingLeaves)) return nullptr;

        return root;
    }
};