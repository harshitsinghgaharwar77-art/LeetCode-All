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
    TreeNode* solve(vector<int>& nums, int left, int right){
        // base case
        if(left > right) return NULL;
        // find maximum value
        int maxi = left;
        for(int i =left; i <= right; i++){
            if(nums[i] > nums[maxi]){
                maxi = i;
            }
        }
        // build root node
        TreeNode* root = new TreeNode(nums[maxi]);
        // build left and right sub trees
        root -> left = solve(nums, left, maxi-1);
        root -> right = solve(nums, maxi+1, right);

        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
};