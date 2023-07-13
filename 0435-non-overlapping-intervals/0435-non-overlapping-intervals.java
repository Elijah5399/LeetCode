class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> a[1] - b[1]);
        int k = Integer.MIN_VALUE, c = 0;
        for (int[] x : intervals) {
            if (x[0] >= k) {
                k = x[1];
            } else {
                c++;
            }
        }
        return c;
    }
}