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
    private List<TreeNode> helper(int low, int high) {
        List<TreeNode> res = new ArrayList<>();
        if (low > high) {
            res.add(null);
            return res;
        }
        for (int i = low; i <= high; i++) {
            List<TreeNode> l = helper(low, i - 1);
            List<TreeNode> r = helper(i + 1, high);
            for (TreeNode t : l) {
                for (TreeNode x : r) {
                    TreeNode root = new TreeNode(i, t, x);
                    res.add(root);
                }
            }
        }
        return res;
    }

    public List<TreeNode> generateTrees(int n) {
        return helper(1, n);
    }
}