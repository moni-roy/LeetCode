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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, nullptr);
    }
    TreeNode *sortedListToBST(ListNode *head, ListNode *tail) {
        if(head == tail) {
            return nullptr;
        }
        if(head->next == tail) {
            TreeNode *t = new TreeNode(head->val);
            return t;
        }
        ListNode *t = head, *m = head;
        while(t!= tail && t->next!=tail) {
            m = m->next;
            t = t->next->next;
        }
        TreeNode *root = new TreeNode(m->val);
        root->left = sortedListToBST(head, m);
        root->right = sortedListToBST(m->next, tail);
        return root;            
    }
};