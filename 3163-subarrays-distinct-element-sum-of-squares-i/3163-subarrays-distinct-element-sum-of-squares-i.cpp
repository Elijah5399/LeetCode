class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            set<int> s;
            for (int j = 0; j + i < n; j++) {
                s.insert(nums[i + j]);
                res += s.size() * s.size();
            }
        }
        return res;
    }
};