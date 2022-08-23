/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head==null || head.next==null) return true;
        
        /* find the mid */
        ListNode slow = head, fast = head.next;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        
        /* reverse tail from mid */
        ListNode mid = slow.next, prev = slow;
        slow.next = null;
        while(mid != null){
            ListNode tmp = mid;
            mid = mid.next;
            tmp.next = prev;
            prev = tmp;
        }
        
        /* check palindrome */
        ListNode start = head, end = prev;
        while(start !=null && start != end){
            if(start.val != end.val) return false;
            start = start.next;
            end = end.next;
        }
        
        return true;
    }
}