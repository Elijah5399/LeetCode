class Solution {
public:
    int memo[501][501];
    int solve(int i, int rem, vector<int>& cost, vector<int>& time, int n) {
        if (rem <= 0) return 0;
        if (i >= n) return INT_MAX;
        if (memo[i][rem] != -1) return memo[i][rem];
        int res = 0;
        res = (int) min((long long) solve(i + 1, rem, cost, time, n), 
            (long long) solve(i + 1, rem - 1 - time[i], cost, time, n) + cost[i]);
        memo[i][rem] = res;
        return res;
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(memo, -1, sizeof(memo));
        int n = cost.size();
        return solve(0, n, cost, time, n);
    }
};