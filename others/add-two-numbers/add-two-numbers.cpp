/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *rt = new ListNode(0);
        int t  =0;
        ListNode *ret = rt, *x=l1, *y=l2;
        while(x || y){
            
            if (x){
                t += x->val;
                x = x->next;
            }
            if (y){
                t += y->val;
                y=y->next;
            }
            rt->val = (t)%10;
            t = t/10;
            if(t|| x || y){
                rt->next = new ListNode(t);
                rt= rt->next;
            }
        }
        return ret;
    }
};