class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        LinkedList<Integer> l = new LinkedList<>();
        for (int i = 0; i < index.length; i++) {
            l.add(index[i], nums[i]);
        }
        int[] ans = new int[l.size()];
        int i = 0;
        while (!l.isEmpty()) {
            int next = l.remove();
            ans[i] = next;
            i++;
        }
        return ans;
    }
}