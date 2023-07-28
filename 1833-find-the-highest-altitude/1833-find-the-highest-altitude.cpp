class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, alt = 0;
        for (auto x : gain) {
            alt += x;
            ans = max(ans, alt);
        }
        return ans;
    }
};