class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        int[][] ans = new int[m][n];
        int y = 0, x = 0;
        if (m * n != original.length) {
            return new int[0][0];
        }
        for (int elem : original) {
            ans[y][x] = elem;
            x++;
            if (x >= n) {
                y++;
                x = 0;
            }
        }
        return ans;
    }
}