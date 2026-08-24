class Solution {
    ListNode* getMidNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // Find middle
        ListNode* mid = getMidNode(head);

        // Reverse second half
        ListNode* head2 = reverseLL(mid);

        // Compare first and second half
        ListNode* temp1 = head;
        ListNode* temp2 = head2;

        while (temp2 != nullptr) {
            if (temp1->val != temp2->val) {
                return false;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return true;
    }
};