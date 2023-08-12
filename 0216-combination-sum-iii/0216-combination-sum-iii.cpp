class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return helper(1, k, n);
    }
    vector<vector<int>> helper(int curr, int k, int goal) {
        vector<vector<int>> res;
        if (curr > goal || curr > 9 || k == 0) {
            return res;
        } else if (curr == goal && k == 1) {
            res.push_back(vector<int>{curr});
            return res;
        }
        vector<vector<int>> next = helper(curr + 1, k - 1, goal - curr);
        for (vector<int> x : next) {
            x.push_back(curr);
            res.push_back(x);
        }
        vector<vector<int>> next2 = helper(curr + 1, k, goal);
        for (vector<int> x : next2) {
            res.push_back(x);
        }
        return res;
    }
};