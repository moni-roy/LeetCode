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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head2 = slow->next;
        slow->next = nullptr;
        head2 = reverse(head2);
        merge(head, head2);
    }
    ListNode* reverse(ListNode* head) {
        ListNode *prev = nullptr, *cur = head, *next;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    void merge(ListNode* head1, ListNode* head2) {
        ListNode *cur1 = head1, *cur2 = head2;
        while (cur1 && cur2) {
            ListNode *next1 = cur1->next;
            ListNode *next2 = cur2->next;
            cur1->next = cur2;
            cur2->next = next1;
            cur1 = next1;
            cur2 = next2;
        }
    }
};