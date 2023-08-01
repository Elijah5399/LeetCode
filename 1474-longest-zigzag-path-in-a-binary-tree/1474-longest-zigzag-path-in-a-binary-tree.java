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
    int ans = 0;
    private void helper(TreeNode node, int curr, boolean goLeft) {
        if (node == null) {
            return;
        }
        ans = Math.max(ans, curr);
        if (goLeft) {
            helper(node.left, curr + 1, false);
            helper(node.right, 1, true);
        } else {
            helper(node.right, curr + 1, true);
            helper(node.left, 1, false);
        }
    }
    public int longestZigZag(TreeNode root) {
        helper(root, 0, true);
        helper(root, 0, false);
        return ans;
    }
}