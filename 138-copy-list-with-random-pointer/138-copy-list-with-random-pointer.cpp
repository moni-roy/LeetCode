/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList1(Node* head) {
        if(!head) return NULL;
        Node* cur = head;
        while(cur){
            Node* newNode = new Node(cur->val);
            newNode->next = cur->next;
            cur->next = newNode;
            cur = newNode->next;
        }
        cur = head;
        while(cur){
            if(cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        Node* newHead = head->next;
        cur = head;
        while(cur){
            Node* newCur = cur->next;
            cur->next = newCur->next;
            if(newCur->next) newCur->next = newCur->next->next;
            cur = cur->next;
        }
        return newHead;
    } // O(n) time, O(1) space

    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        Node* cur = head;
        while(cur){
            Node* newNode = new Node(cur->val);
            m[cur] = newNode;
            cur = cur->next;
        }
        cur = head;
        while(cur){
            m[cur]->next = m[cur->next];
            m[cur]->random = m[cur->random];
            cur = cur->next;
        }
        return m[head];
    } // O(n) time, O(n) space
};