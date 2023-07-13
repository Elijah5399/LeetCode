class Solution {
    public int[][] reconstructQueue(int[][] people) {
        //First sort by decreasing height, then sort by increasing k values
        Arrays.sort(people, (a, b) -> a[0] == b[0] ? a[1] - b[1] : b[0] - a[0]);
        List<int[]> ans = new LinkedList<>();
        for (int[] p : people) {
            ans.add(p[1], p);
        }
        return ans.toArray(new int[people.length][2]);
    }
}