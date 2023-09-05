/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) return null;
        Node res = new Node(head.val);
        Node resPtr = res;
        Map<Node, Node> map = new HashMap<>();
        Node curr = head;
        map.put(curr, res);
        while (curr.next != null) {
            Node next = new Node(curr.next.val);
            map.put(curr.next, next);
            resPtr.next = next;
            resPtr = resPtr.next;
            curr = curr.next;
        }
        curr = head;
        resPtr = res;
        while (curr != null) {
            Node rand = map.get(curr.random);
            resPtr.random = rand;
            curr = curr.next;
            resPtr = resPtr.next;
        }
        return res;
    }
}