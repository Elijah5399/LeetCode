class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;
        int res = 0;
        for (int i = 0; i < n - 2; i++) {
            int b = nums[i + 1] - nums[i];
            for (int j = i + 2; j < n; j++) {
                if (b != nums[j] - nums[j - 1]) break;
                if (j - i >= 2) {
                    res++;
                }
            }
        }
        return res;
    }
};