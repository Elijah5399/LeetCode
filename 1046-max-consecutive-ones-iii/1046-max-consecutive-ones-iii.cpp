class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, zeroes = 0, res = 0;
        while (r < nums.size()) {
            zeroes += (nums[r++] == 0 ? 1 : 0);
            while (zeroes > k) {
                zeroes -= (nums[l++] == 0 ? 1 : 0);
            }
            res = max(res, r - l);
        }
        return res;
    }
};