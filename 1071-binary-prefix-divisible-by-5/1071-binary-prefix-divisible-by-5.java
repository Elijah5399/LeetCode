class Solution {
    public List<Boolean> prefixesDivBy5(int[] nums) {
        List<Boolean> ans = new LinkedList<>();
        int curr = 0;
        for (int num : nums) {
            curr = ((curr << 1) | num) % 5;
            if (curr == 0) {
                ans.add(true);
            } else {
                ans.add(false);
            }
        }
        return ans;
    }
}