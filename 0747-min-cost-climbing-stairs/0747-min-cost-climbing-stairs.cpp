class Solution {
public:
    vector<int> memo;
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for (int i = 0; i < n; i++) {
            memo.push_back(-1);
        }
        return min(calc(0, cost, n), calc(1, cost, n));
    }
    int calc(int i, vector<int>& cost, int n) {
        if (i == n - 1 || i == n - 2) {
            return cost[i];
        } else if (memo[i] != -1) {
            return memo[i];
        }
        int ans =  cost[i] + min(calc(i + 1, cost, n), calc(i + 2, cost, n));
        memo[i] = ans;
        return ans;
    }
};