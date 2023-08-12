class Solution {
public:
    vector<int> memo;
    int tribonacci(int n) {
        memo.push_back(0);
        memo.push_back(1);
        memo.push_back(1);
        for (int i = 3; i <= n; i++) {
            memo.push_back(-1);
        }
        return calc(n);
    }
    int calc(int n) {
        if (memo[n] != -1) {
            return memo[n];
        }
        int ans = calc(n - 1) + calc(n - 2) + calc(n - 3);
        memo[n] = ans;
        return ans;
    }
};