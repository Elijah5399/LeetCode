using ll = long long;

class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ans = 0;
        auto can = [&](vector<int> machine, int numAlloys) {
            ll totalCost = 0;
            for (int i = 0; i < n; i++) {
                ll need = (ll) numAlloys * machine[i] - stock[i];
                if (need > 0) totalCost += need * cost[i];
            }
            return totalCost <= budget;
        };
        for (int i = 0; i < k; i++) {
            int l = 0, h = pow(10, 9), mid = (l + h) >> 1;
            while (l < mid && mid < h) {
                if (can(composition[i], mid)) {
                    l = mid;
                } else {
                    h = mid;
                }
                mid = (l + h) >> 1;
            }
            ans = max(ans, l);
        }
        return ans;
    }
};