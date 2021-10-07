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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *last = head, *nHead;
        int cnt = 0;
        while(last->next) {
            last = last->next;
            cnt++;
            if(cnt == n) {
                nHead = head;
            }
            else if(cnt>n) nHead = nHead->next;
        }
        if(nHead && nHead->next) nHead->next = nHead->next->next;
        else head = head->next;
        return head;
    }
};