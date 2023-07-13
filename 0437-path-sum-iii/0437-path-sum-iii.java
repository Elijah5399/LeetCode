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
    public int pathSum(TreeNode root, int targetSum) {
        return dfs(root, new LinkedList<>(), targetSum);
    }
    private int dfs(TreeNode node, List<Long> sums, int target) {
        if (node == null) {
            return 0;
        }
        int res = node.val == target ? 1 : 0;
        List<Long> next = new LinkedList<>();
        Iterator<Long> i = sums.iterator();
        while (i.hasNext()) {
            long n = i.next();
            if (n + node.val == target) res++;
            next.add(n + node.val);
        }
        next.add((long)node.val);
        int ans = res + dfs(node.left, next, target) + dfs(node.right, next, target);
        //System.out.println("node is: " + node.val + ", ans is: " + ans);
        return ans;
    }
}