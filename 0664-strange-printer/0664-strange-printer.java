class Solution {
    public int strangePrinter(String s) {
        int n = s.length();
        int dp[][] = new int[n][n];
        for (int len = 1; len <= n; len++) {
            for (int left = 0; left <= n - len; left++) {
                int right = left + len - 1;
                dp[left][right] = n;
                /* j is the leftmost char differing from s[right]. j=-1 means
                we haven't found such a char yet */
                int j = -1;
                //i is the index at which we split the left and right substrings
                for (int i = left; i < right; i++) {
                    if (s.charAt(i) != s.charAt(right) && j == -1) {
                        j = i;
                    }
                    if (j != -1) {
                        dp[left][right] = Math.min(1 + dp[j][i] + dp[i + 1][right],
                            dp[left][right]);
                    }
                }
                if (j == -1) {
                    dp[left][right] = 0;
                }
            }
        }
        return dp[0][n-1] + 1;
    }
}