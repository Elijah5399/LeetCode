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
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        Map<Integer, List<Integer>> adjList = new HashMap<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);
        adjList.put(root.val, new LinkedList<>());
        //do BFS on the tree to convert it to an adjacency list
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            if (node.left == null && node.right == null) {
                //do nothing
            } else if (node.left == null) {
                //root.right isn't null
                adjList.get(node.val).add(node.right.val);
                //add root.right to adjList
                List<Integer> add = new LinkedList<>();
                add.add(node.val);
                adjList.put(node.right.val, add);
                q.offer(node.right);
            } else if (node.right == null) {
                //root.left isn't null
                adjList.get(node.val).add(node.left.val);
                //add root.right to adjList
                List<Integer> add = new LinkedList<>();
                add.add(node.val);
                adjList.put(node.left.val, add);
                q.offer(node.left);
            } else {
                //root.left and root.right aren't null
                adjList.get(node.val).add(node.left.val);
                adjList.get(node.val).add(node.right.val);
                //add root.right to adjList
                List<Integer> add = new LinkedList<>();
                add.add(node.val);
                adjList.put(node.left.val, add);
                List<Integer> add2 = new LinkedList<>();
                add2.add(node.val);
                adjList.put(node.right.val, add2);
                q.offer(node.right);
                q.offer(node.left);
            }
        }
        boolean[] visited = new boolean[501];
        visited[target.val] = true;
        List<Integer> frontier = new LinkedList<>();
        List<Integer> nextFrontier = new LinkedList<>();
        int count = 0;
        frontier.add(target.val);
        while (!frontier.isEmpty() && count <= k) {
            //System.out.println("count: " + count);
            if (count == k) {
                return frontier;
            }
            int next = frontier.remove(0);
            List<Integer> neighbours = adjList.get(next);
            while (!neighbours.isEmpty()) {
                int x = neighbours.remove(0);
                if (!visited[x]) {
                    nextFrontier.add(x);
                    visited[x] = true;
                }
            }
            if (frontier.isEmpty() && !nextFrontier.isEmpty()) {
                frontier = nextFrontier;
                nextFrontier = new LinkedList<>();
                count++;
            }
        }
        return frontier;
    }
}