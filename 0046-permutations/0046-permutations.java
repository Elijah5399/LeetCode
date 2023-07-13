class Solution {
    public List<List<Integer>> permute(int[] nums) {
        return helper(nums, 0);
    }
    private List<List<Integer>> helper(int[] nums, int index) {
        if (index == nums.length - 1) {
            List<Integer> a = new ArrayList<>();
            a.add(nums[index]);
            List<List<Integer>> ans = new ArrayList<>();
            ans.add(a);
            return ans;
        }
        List<List<Integer>> x = helper(nums, index + 1);
        List<List<Integer>> ans = new ArrayList<>();
        while (!x.isEmpty()) {
            List<Integer> comb = x.remove(0);
            for (int i = 0; i <= comb.size(); i++) {
                List<Integer> copy = new ArrayList<>();
                for (int j = 0; j < comb.size(); j++) {
                    copy.add(comb.get(j));
                }
                copy.add(i, nums[index]);
                ans.add(copy);
            }
        }
        return ans;
    }
}