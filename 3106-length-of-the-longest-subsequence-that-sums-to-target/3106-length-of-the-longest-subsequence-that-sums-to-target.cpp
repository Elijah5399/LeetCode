class Solution {
public:
    int memo[1001][1001];
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < 1001; i++) {
            for (int j = 0; j < 1001; j++) {
                memo[i][j] = -2;
            }
        }
        return dp(n - 1, target, nums);
    }
    int dp(int index, int target, vector<int>& nums) {
        if (index < 0) {
            return -1;
        } else if (target < 0) {
            return -1;
        } else if (memo[index][target] != -2) {
            return memo[index][target];
        }
        int ans = -1;
        ans = max(ans, dp(index - 1, target, nums));
        if (dp(index - 1, target - nums[index], nums) > -1) {
            ans = max(ans, dp(index - 1, target - nums[index], nums) + 1);
        }
        if (target == nums[index]) {
            ans = max(ans, 1);
        }
        memo[index][target] = ans;
        return ans;
    }
};