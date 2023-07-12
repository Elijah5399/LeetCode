class Solution {
    public int findKthLargest(int[] nums, int k) {
        Queue<Integer> pq = new PriorityQueue<>();
        for (int num : nums) {
            if (pq.size() < k) {
                pq.offer(num);
            } else {
                int next = pq.peek();
                if (next < num) {
                    pq.poll();
                    pq.offer(num);
                }
            }
        }
        return pq.poll();
    }
}