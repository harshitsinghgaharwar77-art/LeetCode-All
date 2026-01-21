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
    private:
    ListNode* solve(ListNode* sorted, ListNode* curr){
        // base case
        if(sorted == NULL || sorted -> val >= curr -> val){
            curr -> next = sorted;
            sorted = curr;
        }
        else{
            ListNode* temp = sorted;
            while(temp -> next != NULL && temp -> next -> val < curr -> val){
                temp = temp -> next;
            }
            curr -> next = temp -> next;
            temp -> next = curr;
        }
        return sorted;
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sorted = nullptr;             // new linked list
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* new_node = curr -> next;
            sorted = solve(sorted, curr);
            curr = new_node;
        }
        return sorted;
    }
};