class Solution {
    public long totalCost(int[] costs, int k, int candidates) {
        int n = costs.length;
        boolean[] added = new boolean[n];
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue(new MyComp());
        int left = 0, right = n-1;
        candidates = Math.min((n + 1) / 2, candidates);
        while (left < candidates) {
            pq.add(new Pair(costs[left], left));
            left++;
        }
        while (right > n - candidates - 1 && right >= left) {
            pq.add(new Pair(costs[right], right));
            right--;
        }
        int hired = 0;
        long cost = 0;
        while (hired < k) {
            Pair<Integer, Integer> next = pq.poll();
            cost += next.getKey();
            int index = next.getValue();
            if (index < left) {
                if (left <= right) {
                    pq.add(new Pair(costs[left], left));
                    left++;
                }
            } else if (index > right) {
                if (left <= right) {
                    pq.add(new Pair(costs[right], right));
                    right--;
                }
            }
            hired++;
        }
        return cost;
    }
    class MyComp implements Comparator<Pair<Integer, Integer>> {
        public int compare(Pair<Integer, Integer> pr1, Pair<Integer, Integer> pr2) {
            if (pr1.getKey() < pr2.getKey()) {
                return -1;
            } else if (pr1.getKey() > pr2.getKey()) {
                return 1;
            } else {
                return pr1.getValue() - pr2.getValue();
            }
        }
    }
}