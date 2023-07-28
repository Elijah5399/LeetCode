class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0, ans = 0, hasOneZero = false;
        while (r < nums.size()) {
            if (hasOneZero) {
                if (nums[r] == 0) {
                    while (nums[l] != 0) {
                        l++;
                    }
                    l++;
                }
            } else {
                hasOneZero = (nums[r] == 0 ? true : false);
            }
            r++;
            ans = max(ans, r - l - 1);
        }
        return ans;
    }
};