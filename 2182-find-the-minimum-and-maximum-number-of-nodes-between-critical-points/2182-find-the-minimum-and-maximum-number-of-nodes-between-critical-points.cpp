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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int minDistance = 1e6;
        int maxDistance = -1;
        int firstInd = -1, last = -1, ind = 1;
        ListNode *prev = head;
        head = head->next;
        while(head->next != nullptr) {
            ListNode *next = head->next;
            if ((prev->val > head->val && head->val < next->val) || (prev->val < head->val && head->val > next->val)) {
                if (firstInd==-1) firstInd = ind;
                if (last != -1) minDistance = min(minDistance, ind - last);
                last = ind;
            }
            ind ++;
            prev = head;
            head = next;
        }
        if (firstInd != last) maxDistance = max(maxDistance, last - firstInd);
        return {minDistance != 1e6 ? minDistance : -1,  maxDistance};
    }
};