class Solution {
    public boolean canMakeArithmeticProgression(int[] arr) {
        Arrays.sort(arr);
        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.length; i++) {
            int currDiff = arr[i] - arr[i - 1];
            if (diff != currDiff) {
                return false;
            }
        }
        return true;
    }
}