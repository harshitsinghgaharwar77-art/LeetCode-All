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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Step 1: Check if there are at least k nodes left
        ListNode* temp = head;
        int count = 0;
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }

        // If less than k nodes, return head without reversing
        if (count < k) return head;

        // Step 2: Reverse first k nodes
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        count = 0;

        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 3: Recursively reverse remaining nodes
        if (next) {
            head->next = reverseKGroup(next, k);
        }

        // Step 4: Return new head after reversal
        return prev;
    }
};
