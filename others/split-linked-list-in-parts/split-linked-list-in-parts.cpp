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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *tmp = head;
        int n = 0;
        while(tmp) {
            n++;
            tmp = tmp->next;
        }
        int w = n/k, r = n%k;
        tmp = head;
        vector<ListNode*> ret(k);
        for(int i = 0; i<k;i++) {
            ListNode *t = tmp;
            for(int j = 0; j<w + ((i < r)?1:0) -1; j++) {
                if(tmp!=nullptr) tmp = tmp->next;
            }
            if(tmp!=nullptr) {
                ListNode *pr = tmp;
                tmp = tmp->next;
                pr->next = nullptr;
            }
            ret[i] = t;
        }
        return ret;
    }
};