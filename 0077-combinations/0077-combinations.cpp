class Solution {
public:
    vector<vector<int>> helper(int start, int end, int numRem) {
        vector<vector<int>> res;
        if (numRem == 1) {
            for (int i = start; i <= end; i++) {
                res.push_back(vector<int>{i});
            }
            return res;
        }
        for (int i = start; i <= end - numRem + 1; i++) {
            vector<vector<int>> rest = helper(i + 1, end, numRem - 1);
            for (vector<int> x : rest) {
                x.push_back(i);
                res.push_back(x);
            }
        }
        return res;
    }

    vector<vector<int>> combine(int n, int k) {
        return helper(1, n, k);
    }
};