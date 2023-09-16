class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        for (auto& x : nums) {
            m[x]++;
        }
        int e = 0, freq = INT_MIN;
        for (auto& x : m) {
            if (x.second > freq) {
                freq = x.second;
                e = x.first;
            }
        }
        int ct = 0;
        for (auto& x : m) {
            if (x.first != e) {
                ct += x.second;
            }
        }
        if (ct < freq) {
            return freq - ct;
        } else {
            if (n % 2 == 0) {
                return 0;
            } else {
                return 1;
            }
        }
    }
};