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
  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k == 1 || head == nullptr) return head;

    ListNode* start = new ListNode(-1);

    start->next = head;
    ListNode* now = start, * next, * prev = start;
    int n = 0;
    while (now) {
      n++;
      now = now->next;
    }
    while (n > k) {
      now = prev->next;
      next = now->next;
      for (int i = 1; i < k; i++) {
        now->next = next->next;
        next->next = prev->next;
        prev->next = next;
        next = now->next;
      }
      prev = now;
      n -= k;
    }
    return start->next;
  }
};