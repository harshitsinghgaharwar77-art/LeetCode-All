/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* curr;
    TreeNode* build_bst(int n)
    {
        // base case
        if(n <= 0)
        {
            return nullptr;
        }

        TreeNode* left = build_bst(n/2);
        TreeNode* root = new TreeNode(curr -> val);
        root -> left = left;

        curr = curr -> next;

        root -> right = build_bst(n-n/2-1);

        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp)
        {
            n++;
            temp = temp -> next;
        }

        curr = head;
        return build_bst(n);
    }
};