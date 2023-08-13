class Solution {
public:
    unordered_map<int, bool> memo;
    bool validPartition(vector<int>& nums) {
        memo[0] = false;
        int n = nums.size();
        memo[1] = nums[0] == nums[1] ? true : false;
        if (n > 2) {
            if ((nums[0] == nums[1] && nums[1] == nums[2]) || (nums[0] + 1 == nums[1] && nums[1] + 1 == nums[2])) {
                memo[2] = true;
            } else {
                memo[2] = false;
            }
        }
        return helper(n - 1, nums, n);
    }
    bool helper(int index, vector<int>& nums, int n) {
        if (index < 0) {
            return true;
        } else if (memo.count(index)) {
            return memo[index];
        }
        bool ans = (nums[index] == nums[index - 1] && helper(index - 2, nums, n)) || (nums[index] == nums[index - 1] && nums[index - 1] == nums[index - 2] && helper(index - 3, nums, n)) || (nums[index] == nums[index - 1] + 1 && nums[index - 1] == nums[index - 2] + 1 && helper(index - 3, nums, n));
        memo[index] = ans;
        return ans; 
    }
};