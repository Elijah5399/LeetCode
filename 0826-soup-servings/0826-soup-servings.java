class Solution {
    Map<Integer, Map<Integer, Double>> dp;
    int[][] servings = {{4, 0}, {3, 1}, {2, 2}, {1, 3}};
    public double soupServings(int n) {
        int m = (int) Math.ceil((double) n / 25);
        Map<Integer, Map<Integer, Double>> dp = new HashMap<>();
        for (int a = 1; a <= m; a++) {
            if (helper(a, a, dp) > 1 - 1e-5) {
                return 1.0;
            }
        }
        return helper(m, m, dp);
    }
    private double helper(int a, int b, Map<Integer, Map<Integer, Double>> dp) {
        if (a == 0 && b == 0) {
            return 0.5;
        } else if (a == 0) {
            return 1.0;
        } else if (b == 0) {
            return 0.0;
        }
        //System.out.println("line A, a: " + a + ",b: " + b);
        if (dp.containsKey(a) && dp.get(a).containsKey(b)) {
            //System.out.println("line B, a: " + a + ",b: " + b);
            return dp.get(a).get(b);
        } 
        double ans = 0.0;
        for (int[] s : servings) {
            ans += helper(Math.max(0, a - s[0]), Math.max(0, b - s[1]), dp);
        }
        ans /= 4;
        if (!dp.containsKey(a)) {
            dp.put(a, new HashMap<>());
        }
        dp.get(a).put(b, ans);
        return ans;
    }
}