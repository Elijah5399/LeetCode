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
    public ListNode deleteMiddle(ListNode head) {
        ListNode curr = head; int n = 1;
        while (curr.next != null) {
            curr = curr.next;
            n++;
        }
        if (n == 1) return null;
        int mid = n / 2;
        ListNode ptr = head;
        while (mid > 1) {
            ptr = ptr.next;
            mid--;
        }
        ptr.next = ptr.next.next;
        return head;
    }
}