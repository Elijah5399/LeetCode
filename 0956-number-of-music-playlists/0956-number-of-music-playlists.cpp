class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        //row: length of playlist, col:
        long long dp[goal + 1][n + 1];
        int MOD = 1000000007;
        for (int i = 0; i <= goal; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for (int i = 1; i <= goal; i++) {
            for (int j = 1; j <= n; j++) {
                if (j > i) continue;
                //add a new different song
                dp[i][j] = dp[i - 1][j - 1] * (n - j + 1);
                dp[i][j] %= MOD;
                if (j > k) {
                    //an old song can be repeated
                    dp[i][j] += dp[i - 1][j] * (j - k);
                    dp[i][j] %= MOD;
                }
            }
        }
        return dp[goal][n];
    }
};