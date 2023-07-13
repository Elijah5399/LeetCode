class Solution {
    public int maxRotateFunction(int[] nums) {
        int max = Integer.MIN_VALUE;
        LinkedList<Integer> l = new LinkedList<>();
        int sum = 0;
        int curr = 0;
        int n = nums.length;
        for (int i = 0; i <nums.length; i++) {
            int num = nums[i];
            curr += i * num;
            sum += num;
            l.add(num);
        }
        max = curr;
        //System.out.println("curr is: " + curr);
        for (int start = 1; start < n; start++) {
            int popped = l.removeLast();
            //System.out.println("popping: " + popped);
            curr -= popped * (n - 1);
            curr += (sum - popped);
            l.addFirst(popped);
            //System.out.println("curr is: " + curr);
            max = Math.max(max, curr);
        }
        return max;
    }
}