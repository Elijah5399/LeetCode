class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for (string x : wordDict) wordSet.insert(x);
        int n = s.size();
        vector<string> dp(n + 1, "");
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j <= n; j++) {
                string x = dp[j];
                string search = s.substr(i, (n - i - x.size()));
                if (wordSet.count(search)) {
                    dp[i] = s.substr(i);
                    break;
                }
            }
        }
        return dp[0] == s;
    }
};