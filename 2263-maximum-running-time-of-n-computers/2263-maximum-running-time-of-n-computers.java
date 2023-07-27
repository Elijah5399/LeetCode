class Solution {
    public long maxRunTime(int n, int[] batteries) {
        if (batteries.length == n) {
            int min = Integer.MAX_VALUE;
            for (int i : batteries) {
                min = Math.min(min, i);
            }
            return min;
        }
        long sum = 0;
        for (int x : batteries) {
            sum += x;
        }
        long l = 0, r = sum / n;
        while (l < r) {
            long mid = r - (r - l) / 2;
            long t = 0;
            for (int batt : batteries) {
                t += Math.min(batt, mid);
            }
            if (t >= (long) n * mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
}