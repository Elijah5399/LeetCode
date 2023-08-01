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
    public int pairSum(ListNode head) {
        ListNode start = head;
        ListNode end = head;
        int len = 1;
        while (end.next != null) {
            end = end.next;
            len += 1;
        }
        int[] arr = new int[len/2];
        int max = -1;
        for (int i = 0; i < len; i++) {
            if (i < (len / 2)) {
                arr[i] = start.val;
            } else {
                int prev = arr[len - i - 1];
                max = Math.max(max, prev + start.val);
            }
            start = start.next;
        }
        return max;
    }
}