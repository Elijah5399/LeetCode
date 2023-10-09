class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return {-1, -1};
        }
        int l = 0, r = n - 1;
        // find starting position
        while (l < r) {
            int mid = (l + r) / 2;
            int curr = nums[mid];
            if (curr < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int start = l;
        if (nums[start] != target) start = -1;
        l = 1; r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            int curr = nums[mid];
            if (curr <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        int end = l - 1;
        if (nums[end] != target) end = -1;
        vector<int> ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};