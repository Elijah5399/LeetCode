class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int n = nums.size();
        bool sorted = true;
        for (int i = 0; i < n; i++) {
            int prev = nums[i];
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > prev) {
                    prev = nums[j];
                } else {
                    sorted = false;
                    break;
                }
            }
            for (int k = 0; k < i; k++) {
                if (nums[k] > prev) {
                    prev = nums[k];
                } else {
                    sorted = false;
                    break;
                }
            }
            if (sorted) {
                return (n - i) % n;
            }
            sorted = true;
        }
        return -1;
    }
};