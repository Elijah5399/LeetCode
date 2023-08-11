class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = vector<int>(amount + 1, -1);
        }
        for (int x = 0; x < n; x++) {
            dp[x][0] = 1;
        }
        return helper(dp, coins, n - 1, amount);
    }
    int helper(vector<vector<int>>& dp, vector<int>& coins, int i, int amt) {
        if (i < 0 || amt < 0) {
            return 0;
        } else if (dp[i][amt] != -1) {
            return dp[i][amt];
        }
        int res = helper(dp, coins, i - 1, amt) + helper(dp, coins, i, amt - coins[i]);
        dp[i][amt] = res;
        return res;
    }
};