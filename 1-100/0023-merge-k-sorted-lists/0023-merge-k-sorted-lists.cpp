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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return usingHeap(lists);
    }
private:
    ListNode* usingHeap(vector<ListNode*>& lists) {
        auto ListNodePtrComp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(ListNodePtrComp)> pq(ListNodePtrComp);
        for (auto l : lists) {
            if (l) pq.push(l);
        }
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            cur->next = node;
            cur = cur->next;
            if (node->next) pq.push(node->next);
        }
        return dummy->next;
    }
};