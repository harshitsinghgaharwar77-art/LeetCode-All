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
    ListNode* oddEvenList(ListNode* head) {
        // edge case
        if(head == nullptr){
            return nullptr;
        }
        if (head -> next == nullptr)
        {
            return head;
        }
        
        ListNode* oddHead = head;
        ListNode* oddTail = head;
        ListNode* evenHead = head -> next;
        ListNode* eventail = head -> next;

        while (eventail != nullptr && eventail -> next != nullptr)
        {
            oddTail -> next = eventail -> next;
            oddTail = eventail -> next;

            eventail -> next = oddTail -> next;
            eventail = oddTail -> next;
        }
        oddTail -> next = evenHead;
        return oddHead;
    }
};