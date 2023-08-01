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
    private void insertNode(TreeNode base, TreeNode toInsert) {
        TreeNode ptr = base;
        while (ptr.right != null) {
            ptr = ptr.right;
        }
        ptr.right = toInsert;
    }
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) {
            return null;
        }
        if (root.val == key) {
            if (root.left == null && root.right == null) {
                return null;
            } else if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            } else {
                if (root.right.left == null) {
                    root.right.left = root.left;
                    return root.right;
                } else {
                    insertNode(root.left, root.right.left);
                    root.right.left = root.left;
                    return root.right;
                }
            }
        } else if (key > root.val) {
            TreeNode r = deleteNode(root.right, key);
            root.right = r;
            return root;
        } else {
            TreeNode l = deleteNode(root.left, key);
            root.left = l;
            return root;
        }
    }
}