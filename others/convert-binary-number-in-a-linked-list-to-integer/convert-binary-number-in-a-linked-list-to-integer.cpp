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
    int getDecimalValue(ListNode* head) {
        int pw = 0;
        int ans = 0;
        while(head) {
            if(ans>0) ans <<= 1;
            if(head->val) ans += 1;
            head = head->next;
        }
        return ans;
    }
};