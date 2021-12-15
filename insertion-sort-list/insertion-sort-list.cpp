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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = head->next;
        ListNode* pre = head;
        while(cur != nullptr){
            if(cur->val < pre->val){
                ListNode* tmp = dummy;
                while(tmp->next->val < cur->val) tmp = tmp->next;
                pre->next = cur->next;
                cur->next = tmp->next;
                tmp->next = cur;
                cur = pre->next;
            }else{
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy->next;   
    }
};