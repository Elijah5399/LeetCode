class Solution {
    public int totalSteps(int[] nums) {
        //use a monotonic decreasing stack
        //iterate forwards
        Stack<int[]> s = new Stack<>();
        s.push(new int[]{nums[0], 0});
        int max = 0;
        for (int i = 1; i < nums.length; i++) {
            int time = 0;
            while (!s.isEmpty() && s.peek()[0] <= nums[i]) {
                time = Math.max(time, s.peek()[1]);
                s.pop();
            }
            if (s.isEmpty()) {
                time = 0;
            } else {
                time++;
            }
            max = Math.max(max, time);
            s.push(new int[]{nums[i], time});
        }
        return max;
    }
}