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
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode answer = head;
        ListNode oddPtr = head, evenPtr = head.next, startEven = head.next;
        while (oddPtr.next != null && evenPtr.next != null) {
            oddPtr.next = evenPtr.next;
            oddPtr = oddPtr.next;
            evenPtr.next = oddPtr.next;
            evenPtr = evenPtr.next;
        }
        oddPtr.next = startEven;
        return answer;
    }
}
//    |   .
// [1,3,5,2,4]
//          ^
//my ans [1,5,4] [3,2]
