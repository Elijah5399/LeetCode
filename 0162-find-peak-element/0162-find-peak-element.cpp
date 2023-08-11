class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int n = nums.size(), low = 0, high = n - 1;
        while (low < high) {
            int mid = (low + high) / 2;
            cout << "mid: " << mid << endl;
            if (mid == 0) {
                if (nums[1] < nums[0]) {
                    return 0;
                } else {
                    low = mid + 1;
                }
            } else if (mid == n - 1) {
                if (nums[mid] <= nums[mid - 1]) {
                    high = mid - 1;
                } else {
                    return n - 1;
                }
            } else {
                if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                    return mid;
                } else if (nums[mid - 1] < nums[mid]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return low;
    }
};