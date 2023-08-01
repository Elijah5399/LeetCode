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
    List<Integer> levelSums;
    public int maxLevelSum(TreeNode root) {
        this.levelSums = new ArrayList<>();
        BFS(root, 1);
        int max = Integer.MIN_VALUE;
        int maxLv = 1;
        for (int i = 0; i < this.levelSums.size(); i++) {
            if (this.levelSums.get(i) > max) {
                max = this.levelSums.get(i);
                maxLv = i + 1;
            }
        }
        return maxLv;
    }
    private void BFS(TreeNode node, int level) {
        if (node == null) {
            return;
        }
        if (this.levelSums.size() <= level - 1) {
            this.levelSums.add(node.val);
        } else {
            int prev = this.levelSums.get(level - 1);
            this.levelSums.set(level - 1, prev + node.val);
        }
        BFS(node.left, level + 1);
        BFS(node.right, level + 1);
    }
}