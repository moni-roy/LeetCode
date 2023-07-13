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
    int pairSum(ListNode* head) {
        ListNode* slow = head, *fast = head, *rev = nullptr;

        while (fast && fast->next) {
            ListNode *tmp = slow;
            slow = slow->next;
            fast = fast->next->next;
            tmp->next = rev;
            rev = tmp;

        }
        int sum = 0;
        while (slow) {
            sum = max(sum, slow->val + rev->val);
            slow = slow->next;
            rev = rev->next;
        }
        return sum;
    }
};