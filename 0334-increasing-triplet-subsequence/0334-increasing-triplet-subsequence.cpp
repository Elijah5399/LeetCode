class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> mins(n), maxs(n);
        mins[0] = nums[0]; maxs[n-1] = nums[n-1];
        for (int i = 1; i < n; i++) {
            mins[i] = min(mins[i - 1], nums[i]);
            maxs[n - 1 - i] = max(nums[n - 1 - i], maxs[n - i]);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > mins[i] && nums[i] < maxs[i]) return true;
        }
        return false;
    }
};