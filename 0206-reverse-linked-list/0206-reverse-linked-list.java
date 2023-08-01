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
    Stack<ListNode> stk;
    public ListNode reverseList(ListNode head) {
        this.stk = new Stack<>();
        if (head == null) {
            return null;
        }
        ListNode ptr = head;
        while (ptr.next != null) {
            stk.push(ptr);
            ptr = ptr.next;
        }
        ListNode newHead = ptr;
        while (!stk.isEmpty()) {
            ListNode next = stk.pop();
            ptr.next = next;
            ptr = next;
        }
        ptr.next = null;
        return newHead;
    }
}