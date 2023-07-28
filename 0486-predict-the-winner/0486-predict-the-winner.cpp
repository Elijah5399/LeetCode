class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        //cout << helper(0, n-1, nums, true) << endl;
        return helper(0, n - 1, nums, true) >= (double) sum / 2;
    }
    long long helper(int l, int r, vector<int>& nums, bool p1turn) {
        //returns the max score p1 can get
        if (l == r) {
            if (p1turn) {
                return nums[l];
            } else {
                return 0;
            }
        }
        if (p1turn) {
            return max(nums[l] + helper(l + 1, r, nums, false), 
                        nums[r] + helper(l, r - 1, nums, false));
        } else {
            return min(helper(l + 1, r, nums, true), helper(l, r - 1, nums, true));
        }
    }
};