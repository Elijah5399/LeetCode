class Solution {
    Map<Pair<Integer, Integer>, Integer> memo;
    /*
    [1,2,3,4,5]
    */
    public int mctFromLeafValues(int[] arr) {
        this.memo = new HashMap<>();
        //think about recursion: Add the min answer from left to root.val and to min answer from right
        int[][] sorted = new int[arr.length][2];
        for (int i = 0; i < arr.length; i++) {
            sorted[i] = new int[]{arr[i], i}; //val then index
        }
        Arrays.sort(sorted, (a, b) -> a[0] - b[0]);
        return helper(arr, 0, arr.length, sorted);
    }
    private int helper(int[] arr, int left, int right, int[][] sorted) { //right exclusive
        //stop condition: arr.length == 1 => i am at a leaf node!
        if (right - left == 1) {
            return 0;
        }
        if (memo.containsKey(new Pair(left, right))) {
            return memo.get(new Pair(left, right));
        }
        int filled = 0;
        //current node value is the max 2 vals in the arr
        int curr = 1;
        int index = arr.length - 1;
        while (filled < 2) {
            if (sorted[index][1] >= left && sorted[index][1] < right) {
                filled++;
                curr *= sorted[index][0];
            }
            index--;
        }
        //System.out.println("left is: " + left + "right is: " + right + "curr is: " + curr);
        int min = Integer.MAX_VALUE;
        for (int i = left + 1; i < right; i++) {
            //[1,2,3,4,5]
            int leftScore = helper(arr, left, i, sorted);
            int rightScore = helper(arr, i, right, sorted);
            min = Math.min(min, leftScore + rightScore);
        }
        int ans = min + curr;
        memo.put(new Pair(left, right), ans);
        return ans;
    }
}

