class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m = 0;
        for (auto c : candies) {
            m = max(m, c);
        }
        vector<bool> ans;
        for (auto c : candies) {
            if (c + extraCandies >= m) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }
        return ans;
    }
};