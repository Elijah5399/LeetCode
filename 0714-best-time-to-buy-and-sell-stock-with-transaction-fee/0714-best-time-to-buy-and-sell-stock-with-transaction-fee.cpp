class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 1) return 0;
        vector<int> withStock(n + 1, -1);
        vector<int> withoutStock(n + 1, -1);
        withoutStock[1] = 0;
        withStock[1] = -prices[0];
        for (int i = 2; i <= n; i++) {
            withoutStock[i] = max(withoutStock[i - 1], withStock[i - 1] + prices[i - 1] - fee);
            withStock[i] = max(withStock[i - 1], withoutStock[i - 1] - prices[i - 1]);
        }
        return withoutStock[n];
    }
};