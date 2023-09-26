class Solution {
public:
    int getOnes(int x) {
        int res = 0;
        while (x > 0) {
            res += x & 1;
            x >>= 1;
        }
        return res;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++) {
            res.push_back(getOnes(i));
        }
        return res;
    }
};