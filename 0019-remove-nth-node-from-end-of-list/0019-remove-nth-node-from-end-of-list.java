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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        Stack<ListNode> s = new Stack<>();
        ListNode c = head;
        while (c != null) {
            s.push(c);
            c = c.next;
        }
        ListNode end = null;
        for (int i = 1; i < n; i++) {
            ListNode ne = s.pop();
            end = ne;
        }
        s.pop();
        if (s.isEmpty()) {
            return end;
        }
        ListNode startRep = s.pop();
        startRep.next = end;
        return head;
    }
}