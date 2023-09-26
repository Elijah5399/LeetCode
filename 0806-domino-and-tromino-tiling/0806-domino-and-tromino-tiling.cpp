class Solution {
    int MOD = 1e9 + 7;
public:
    int numTilings(int n) {
        /*
            base case:
            n == 1: 1 way
            n == 2: 2 ways
            n == 3: 5 ways
        */
        vector<long long> res(1001, -1);
        res[1] = 1;
        res[2] = 2;
        res[3] = 5;
        for (int i = 4; i <= 1000; i++) {
            res[i] = 2 * res[i - 1] + res[i - 3];
            res[i] %= MOD;
        }
        return res[n];
    }
};