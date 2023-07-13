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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *cur = head, *prev = nullptr;
        
        while(left > 1) {
            prev = cur;
            cur = cur->next;
            left = left - 1;
            right = right - 1;
        }
        
        ListNode *start = prev, *end = cur;
        
        while(right--) {
            ListNode *t = cur->next;
            cur->next = prev;
            prev = cur;
            cur = t;
        }
        if(start != nullptr) {
            start->next = prev;
        }
        else {
            head = prev;
        }
        end->next = cur;
        return head;
    }
};