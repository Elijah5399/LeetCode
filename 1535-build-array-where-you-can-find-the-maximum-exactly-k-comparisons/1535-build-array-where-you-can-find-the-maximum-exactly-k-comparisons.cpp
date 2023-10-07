

class Solution {
public:
int MOD = 1000000007;

    int numOfArrays(int n, int m, int k) {
        using ll = long long;
        // n is no. of elems in arr,
        // m is the max elem that can be in the arr
        // k is the search_cost
        /* recursive relation: 
            Want to find dp(n, anything, 0)
            Given dp(i, maxSoFar, rem),
            dp(i + 1, maxSoFar, rem) += ~
            for all dp(i + 1, [maxSoFar, m], rem - 1) += ~

            Base cases:
            1. When i == 1 and rem == k - 1, set dp = 1
        */
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, 0)));
        for (int x = 1; x <= m; x++) {
            dp[1][x][k - 1] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int x = k; x >= 0; x--) {
                    // ll b = (ll)j * dp[i][j][x];
                    // int c = (int)(b % MOD);
                    // dp[i + 1][j][x] += j * dp[i][j][x];
                    // dp[i + 1][j][x] %= MOD;
                    // dp[i + 1][j][x] = (int)((ll) j * dp[i][j][x] % MOD);
                    // cout << "c is: " << c << endl;
                    for (int a = 1; a <= j; a++) {
                        dp[i + 1][j][x] += dp[i][j][x];
                        dp[i + 1][j][x] %= MOD;
                    }
                    for (int a = j + 1; a <= m && x > 0; a++) {
                        dp[i + 1][a][x - 1] += dp[i][j][x];
                        dp[i + 1][a][x - 1] %= MOD;
                    }
                }
            }
        }
        int res = 0;
        for (int a = 1; a <= m; a++) {
            res += dp[n][a][0];
            res %= MOD;
        }
        return res;
    }
};