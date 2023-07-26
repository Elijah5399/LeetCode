class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        int count = 0;
        sort(nums.begin(), nums.end());
        while (l < r) {
            int left = nums[l], right = nums[r];
            if (left + right == k) {
                l++;
                r--;
                count++;
            } else if (left + right < k) {
                l++;
            } else {
                r--;
            }
        }
        return count;
    }
};