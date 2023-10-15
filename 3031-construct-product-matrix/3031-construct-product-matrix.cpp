class Solution {
    #define ll long long
public:
    int MOD = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = 1;
            }
        }
        ll a = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] *= a;
                res[i][j] %= MOD;
                a = a * grid[i][j] % MOD;
            }
        }
        ll b = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                res[i][j] *= b;
                res[i][j] %= MOD;
                b = b * grid[i][j] % MOD;
            }
        }
        return res;
    }
};