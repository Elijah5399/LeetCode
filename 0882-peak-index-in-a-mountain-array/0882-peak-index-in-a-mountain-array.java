class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int n = arr.length;
        int l = 1, r = n - 2;
        while (l < r) {
            int mid = (l + r) / 2;
            if (arr[mid-1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            } else if (arr[mid-1] < arr[mid]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
}