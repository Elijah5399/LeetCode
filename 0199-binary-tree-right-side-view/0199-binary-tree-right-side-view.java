/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    List<Integer> ans;
    public List<Integer> rightSideView(TreeNode root) {
        this.ans = new LinkedList<>();
        if (root == null) return ans;
        Queue<TreeNode> frontier = new LinkedList<>();
        frontier.add(root);
        filler(frontier);
        return ans;
    }
    private void filler(Queue<TreeNode> frontier) {
        int x = 0;
        if (frontier.isEmpty()) {
            return;
        }
        Queue<TreeNode> nextFrontier = new LinkedList<>();
        while (!frontier.isEmpty()) {
            TreeNode next = frontier.poll();
            x = next.val;
            if (next.left != null) {
                nextFrontier.offer(next.left);
            } if (next.right != null) {
                nextFrontier.offer(next.right);
            }
        }
        ans.add(x);
        filler(nextFrontier);
    }
}