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
    private int dfs(int max, TreeNode node) {
        if (node == null) return 0;
        if (node.val >= max) {
            return 1 + dfs(node.val, node.left) + dfs(node.val, node.right);
        } else {
            return dfs(max, node.left) + dfs(max, node.right);
        }
    }
    public int goodNodes(TreeNode root) {
        return dfs(Integer.MIN_VALUE, root);
    }
}