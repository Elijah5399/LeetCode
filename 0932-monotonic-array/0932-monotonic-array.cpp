class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int n = nums.size();
        bool inc = true, dec = true;
        for (int i = 1; i < n; i++) {
            inc = inc && nums[i] >= nums[i - 1];
            dec = dec && nums[i] <= nums[i - 1];
        }
        return inc || dec;
    }
};