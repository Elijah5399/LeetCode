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
    public int maxDepth(TreeNode root) {
        return DFS(root, 0);
    }
    //root is at height 1
    public int DFS(TreeNode node, int height) {
        if (node == null) {
            return height;
        } 
        return Math.max(DFS(node.left, height + 1), DFS(node.right, height + 1));
    }
}