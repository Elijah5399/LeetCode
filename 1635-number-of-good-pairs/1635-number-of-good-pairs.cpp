class Solution {
public:
    int AP(int x) {
        return (int) ((double) x / 2 * (x - 1));
    }
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> freq;
        for (auto& x : nums) {
            freq[x]++;
        }
        int res = 0;
        for (auto& pr : freq) {
            if (pr.second > 1) res += AP(pr.second);
        }
        return res;
    }
};