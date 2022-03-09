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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        head = new ListNode(0, head);
        ListNode* cur = head->next, *pre = head;
        while(cur != nullptr){
            if(cur->next != nullptr && cur->val == cur->next->val){
                while(cur->next != nullptr && cur->val == cur->next->val){
                    cur = cur->next;
                }
                pre->next = cur->next;
                cur = cur->next;
                
            }else{
                pre = cur;
                cur = cur->next;
            }
        }
        return head->next;
    }
};