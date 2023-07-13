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
    ListNode* partition(ListNode* head, int x) {
        ListNode *small = new ListNode();
        ListNode *Hs = small;
        ListNode *big = new ListNode();
        ListNode *Hb = big;
        while(head) {
            if(head->val <x) {
                small->next = head;
                small = small->next;
            }
            else {
                big->next = head;
                big = big->next;
            }
            head = head->next;
        }
        big->next = nullptr;
        small->next = Hb->next;
        return Hs->next;
    }
};