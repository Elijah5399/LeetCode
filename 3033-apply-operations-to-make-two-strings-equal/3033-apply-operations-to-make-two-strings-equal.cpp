class Solution {
public:
    int dp[501][501];
    int solve(int l, int r, vector<int>& a, int x) {
        if (l >= r) return 0; // invalid query
        if (dp[l][r] != -1) return dp[l][r];
        int ans = min({min(x, a[l + 1] - a[l]) + solve(l + 2, r, a, x), 
            min(x, a[r] - a[l]) + solve(l + 1, r - 1, a, x),
            min(x, a[r] - a[r - 1]) + solve(l, r - 2, a, x)});
        dp[l][r] = ans;
        return ans;
    }
    int minOperations(string s1, string s2, int x) {
        vector<int> diffs;
        int n = s1.length();
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                diffs.push_back(i);
            }
        }
        if (diffs.size() % 2  != 0) {
            return -1;
        } else if (diffs.size() == 0) {
            return 0;
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, diffs.size() - 1, diffs, x);
    }
};