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
    private List<Integer> getSeq(TreeNode node) {
        if (node.left == null && node.right == null) {
            List<Integer> res = new ArrayList<>();
            res.add(node.val);
            return res;
        } else if (node.left == null) {
            return getSeq(node.right);
        } else if (node.right == null) {
            return getSeq(node.left);
        } else {
            List<Integer> left = getSeq(node.left);
            List<Integer> right = getSeq(node.right);
            left.addAll(right);
            return left;
        }
        
    }  
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        return getSeq(root1).equals(getSeq(root2));
    }
}