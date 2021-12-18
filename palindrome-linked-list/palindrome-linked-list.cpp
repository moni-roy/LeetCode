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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head, *fast = head, *rev = NULL, *tmp = NULL;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            tmp = slow->next;
            slow->next = rev;
            rev = slow;
            slow = tmp;
        }
        if(fast != NULL) slow = slow->next;
        while(rev != NULL && slow != NULL){
            if(rev->val != slow->val) return false;
            rev = rev->next;
            slow = slow->next;
        }
        return true;
    }
};