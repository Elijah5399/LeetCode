class Solution {
    Map<Integer, List<Integer>> adjList;
    int numCourses;
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        this.adjList = new HashMap<>();
        this.numCourses = numCourses;
        for (int i = 0; i < numCourses; i++) {
            this.adjList.put(i, new ArrayList<>());
        }
        for (int[] prereq : prerequisites) {
            this.adjList.get(prereq[1]).add(prereq[0]);
        }
        boolean ans = true;
        for (int i = 0; i < numCourses; i++) {
            boolean[] visited = new boolean[numCourses];
            ans = ans && dfs(i, visited, i);
        }
        return ans;
    }
    
    private boolean dfs(int start, boolean[] visited, int curr) {
        visited[curr] = true;
        List<Integer> connected = this.adjList.get(curr);
        boolean ans = true;
        for (int i = 0; i < connected.size(); i++) {
            if (connected.get(i) == start) return false;
            if (!visited[connected.get(i)]) {
                ans = ans && dfs(start, visited, connected.get(i));
            }
        }
        return ans;
    }
}