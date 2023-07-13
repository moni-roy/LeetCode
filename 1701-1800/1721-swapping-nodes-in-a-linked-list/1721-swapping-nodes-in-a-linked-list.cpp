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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr)
            return head;
        vector<ListNode*> nodes;
        ListNode* cur = head;
        while(cur != nullptr){
            nodes.push_back(cur);
            cur = cur->next;
        }
        int n = nodes.size();
        // swap kth node from first and last
        swap(nodes[k-1], nodes[n-k]);
        // connect the nodes
        for(int i = 0; i < n-1; i++){
            nodes[i]->next = nodes[i+1];
        }
        nodes[n-1]->next = nullptr;
        return nodes[0];
    }
};