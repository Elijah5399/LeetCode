class Solution {
public:
    int dp[501][501];
    int solve(int i, int j, int m, int n, vector<int>& nums1, vector<int>& nums2) {
        // if (i == m || j == n) return 0;
        if (i == m || j == n) {
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        int ans = max({nums1[i] * nums2[j] + solve(i + 1, j + 1, m, n, nums1, nums2),
            solve(i + 1, j, m, n, nums1, nums2), solve(i, j + 1, m, n, nums1, nums2)});
        dp[i][j] = ans;
        return ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int n1_min = INT_MAX, n1_max = INT_MIN, n2_min = INT_MAX, n2_max = INT_MIN;
        for (int i = 0; i < m; i++) {
            n1_min = min(n1_min, nums1[i]);
            n1_max = max(n1_max, nums1[i]);
        }
        for (int i = 0; i < n; i++) {
            n2_min = min(n2_min, nums2[i]);
            n2_max = max(n2_max, nums2[i]);
        }
        if (n1_min > 0 && n2_max < 0) {
            return n1_min * n2_max;
        }
        if (n2_min > 0 && n1_max < 0) {
            return n2_min * n1_max;
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, m, n, nums1, nums2);
    }
};