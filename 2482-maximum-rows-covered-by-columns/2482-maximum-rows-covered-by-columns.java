class Solution {
    HashMap<Integer, HashMap<Integer, Integer>> map;
    public int maximumRows(int[][] matrix, int numSelect) {
        int m = matrix.length;
        int n = matrix[0].length;
        this.map = new HashMap<>();
        return helper(matrix, numSelect, 0, m, n);
    }
    private int helper(int[][] matrix, int numSelect, int memo, int m, int n) {
        if (this.map.containsKey(numSelect) && this.map.get(numSelect).containsKey(memo)) {
            return this.map.get(numSelect).get(memo);
        }
        if (numSelect == 0) {
            int covered = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] == 1 && ((memo & (1 << j)) == 0)) {
                        //row is not covered
                        break;
                    }
                    if (j == n - 1) {
                        covered++;
                    }
                }
            }
            return covered;
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            if ((memo & (1 << i)) == 0) {
                //column not taken
                memo += (1 << i);
                max = Math.max(max, helper(matrix, numSelect - 1, memo, m, n));
                memo -= (1 << i);
            }
        }
        if (!this.map.containsKey(numSelect)) {
            HashMap<Integer, Integer> newMap = new HashMap<>();
            newMap.put(memo, max);
            this.map.put(numSelect, newMap);
        } else {
            this.map.get(numSelect).put(memo, max);
        }

        return max;
    }
}