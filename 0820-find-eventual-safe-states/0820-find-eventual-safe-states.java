class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        List<Integer> l1 = new LinkedList<>();
        Set<Integer> s = new HashSet<>();
        for (int i = 0; i < graph.length; i++) {
            if (graph[i].length == 0) {
                l1.add(i);
                s.add(i);
            }
        }
        List<Integer> l2 = new LinkedList<>();
        while (!l1.equals(l2)) {
            for (int i = 0; i < graph.length; i++) {
                if (checksafe(i, graph, s)) {
                    l2.add(i);
                    s.add(i);
                }
            }
            if (!l1.equals(l2)) {
                l1 = l2;
                l2 = new LinkedList<>();
            }
        }
        return l2;
    }
    private boolean checksafe(int x, int[][] graph, Set<Integer> terminal) {
        int[] connected = graph[x];
        for (int c : connected) {
            if (!terminal.contains(c)) {
                return false;
            }
        }
        return true;
    }
}