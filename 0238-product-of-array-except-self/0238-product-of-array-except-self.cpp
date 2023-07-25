class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefixPdt = {1};
        for (int i = 0; i < nums.size() - 1; i++) {
            prefixPdt.push_back(nums[i] * prefixPdt.back());
        }
        vector<int> suffixPdt = {1};
        for (int i = nums.size() - 1; i > 0; i--) {
            suffixPdt.push_back(nums[i] * suffixPdt.back());
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            res.push_back(prefixPdt[i] * suffixPdt[nums.size() - 1 - i]);
        }
        return res;
    }
};