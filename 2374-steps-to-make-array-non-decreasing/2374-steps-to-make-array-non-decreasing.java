class Solution {
    public int totalSteps(int[] nums) {
        //use a monotonic non-decreasing stack
        //iterate backwards
        int[] dp = new int[nums.length];
        Stack<int[]> stk = new Stack<>();
        int max = 0;
        for (int i = nums.length - 1; i >= 0; i--) {
            int elem = nums[i];
            while (!stk.isEmpty() && elem > stk.peek()[0]) {
                dp[i] = Math.max(dp[i] + 1, dp[stk.pop()[1]]);
                max = Math.max(max, dp[i]);
            }
            stk.push(new int[]{elem, i});
        }
        return max;
    }
}