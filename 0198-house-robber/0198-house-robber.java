class Solution {
    int[] memo;
    public int rob(int[] nums) {
        //if i have robbed the i-th house, i cannot rob houses i-1, i or i+1!!!!!
        //[1, 2, 3, 4, 5000, 6, 7, 8]
        //if i just robbed house i, then i HAVE to rob either house i + 2 or i + 3
        //potential DP problem: state depends on the index
        this.memo = new int[nums.length];
        Arrays.fill(this.memo, -1);
        if (nums.length == 1) return nums[0];
        return Math.max(helper(0, nums), helper(1, nums));
    }
    private int helper(int i, int[] nums) {
        //returns me the max amt of money i can rob starting from house i
        if (i >= nums.length) {
            return 0;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        if (i == nums.length - 1 || i == nums.length - 2) {
            memo[i] = nums[i];
            return nums[i];
        }
        if (i == nums.length - 3) {
            int ans = nums[i] + nums[i + 2];
            memo[i] = ans;
            return ans;
        }
        int ans = nums[i] + Math.max(helper(i + 2, nums), helper(i + 3, nums));
        memo[i] = ans;
        return ans;
    }
}