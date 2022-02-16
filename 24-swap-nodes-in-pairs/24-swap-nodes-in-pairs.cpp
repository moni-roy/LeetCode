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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        dummy->next = head;

        while(head && head->next){
            // node to be swapped
            ListNode* first = head;
            ListNode* second = head->next;

            // swaping nodes
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // move prev and head
            prev = first;
            head = first->next;
        }
        return dummy->next;
    }
};