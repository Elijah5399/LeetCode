/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        while (slow != fast) {
            if (slow.next != null) {
                slow = slow.next;
            }
            if (fast.next != null && fast.next.next != null) {
                fast = fast.next.next;
            } else if (fast.next == null) {
                
            } else if (fast.next.next == null) {
                fast = fast.next;
            }
        }
        return slow.next != null;
    }
}