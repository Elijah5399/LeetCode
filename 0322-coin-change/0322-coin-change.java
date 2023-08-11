class Solution {
    int[] coins;
    int n;
    int[][] dp;
    public int coinChange(int[] coins, int amount) {
        //Arrays.sort(coins);
        this.coins = coins;
        int n = coins.length;
        int[][] dp = new int[n][amount + 1];
        for (int[] x : dp) {
            Arrays.fill(x, -1);
        }
        this.dp = dp;
        this.n = n;
        int ans = helper(coins.length - 1, amount);
        if (ans >= 100000) {
            return -1;
        } else {
            return ans;
        }
    }
    private int helper(int i, int rem) {
        //returns the fewest number of coins to make up that amt, with rem coins
        //and starting from index i
        if (rem == 0) {
            return 0;
        }
        if (rem < 0 || i < 0) {
            return 100000;
        }
        if (dp[i][rem] != -1) {
            return dp[i][rem];
        }
        int ans = Math.min(1 + helper(i, rem - coins[i]), helper(i - 1, rem));
        dp[i][rem] = ans;
        return ans;
    }
}