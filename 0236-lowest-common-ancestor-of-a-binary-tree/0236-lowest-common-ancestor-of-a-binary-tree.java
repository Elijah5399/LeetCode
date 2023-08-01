/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private Pair<TreeNode, Integer> dfs(TreeNode node, TreeNode p, TreeNode q) {
        //0: contains none, 1: contains p, 2: contains q, 3: contains both
        if (node == null) return new Pair(null, 0);
        Pair<TreeNode, Integer> l = dfs(node.left, p, q);
        if (l.getValue() == 3) return l;
        Pair<TreeNode, Integer> r = dfs(node.right, p, q);
        if (r.getValue() == 3) return r;
        if (node == p) {
            if (l.getValue() == 0 && r.getValue() == 0) {
                return new Pair(node, 1);
            } else if (l.getValue() == 2 || r.getValue() == 2) {
                return new Pair(node, 3);
            }
        } else if (node == q) {
            if (l.getValue() == 0 && r.getValue() == 0) {
                return new Pair(node, 2);
            } else if (l.getValue() == 1 || r.getValue() == 1) {
                return new Pair(node, 3);
            }
        } else {
            //alr checked that both l and r don't contain both 
            //current node isn't p or q
            if (l.getValue() == 1 || l.getValue() == 2) {
                //if l contains either p or q
                if (r.getValue() == 3 - l.getValue()) {
                    return new Pair(node, 3);
                } else {
                    return l;
                }
            } else if (r.getValue() == 1 || r.getValue() == 2) {
                //l val is 0
                return r;
            } else {
                return new Pair(node, 0);
            }
        }
        return new Pair(node, 0);
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return dfs(root, p, q).getKey();
    }
}