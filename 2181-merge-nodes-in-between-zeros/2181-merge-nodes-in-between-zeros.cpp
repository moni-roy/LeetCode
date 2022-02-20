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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> sum;
        int carry = 0;
        while (head) {
            if(head->val == 0) {
                if(carry) {
                    sum.push_back(carry);
                    carry = 0;
                }
            }
            carry += head->val;
            head = head->next;
        }
        if(carry) sum.push_back(carry);
        ListNode* newHead = new ListNode(0);
        ListNode* cur = newHead;
        
        for(int i = 0; i < sum.size(); i++) {
            cur->next = new ListNode(sum[i]);
            cur = cur->next;
        }
        return newHead->next;
    }
};