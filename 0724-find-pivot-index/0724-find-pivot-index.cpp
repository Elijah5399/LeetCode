class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n + 2);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        prefixSum[n + 1] = prefixSum[n];
        for (int i = 1; i < n + 1; i++) {
            if (prefixSum[n + 1] - prefixSum[i] == prefixSum[i - 1]) {
                return i - 1;
            }
        }
        return -1;
    }
};