class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int lb = n / 3;
        map<int, int> m;
        for (int x : nums) {
            m[x]++;
        }
        vector<int> ans;
        for (auto& pr : m) {
            if (pr.second > lb) {
                ans.push_back(pr.first);
            }
        }
        return ans;
    }
};