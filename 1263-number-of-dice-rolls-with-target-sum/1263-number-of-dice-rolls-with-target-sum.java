class Solution {
    public int numRollsToTarget(int n, int m, int X) {
        int MOD = 1000000007;
        int[][] dp = new int[n + 1][X + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= X; j++) {
                for (int k = 1; k <= m; k++) {
                    if (j >= k) {
                        dp[i][j] += dp[i - 1][j - k];
                        dp[i][j] %= MOD;
                    } else {
                        break;
                    }
                }
            }
        }
        return dp[n][X];
	}
}