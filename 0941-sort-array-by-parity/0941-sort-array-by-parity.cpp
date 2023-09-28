class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return nums;
        vector<int> res;
        for (int x : nums) {
            if (x % 2 == 0) res.push_back(x);
        }
        for (int x : nums) {
            if (x % 2 == 1) res.push_back(x);
        }
        return res;
    }
};