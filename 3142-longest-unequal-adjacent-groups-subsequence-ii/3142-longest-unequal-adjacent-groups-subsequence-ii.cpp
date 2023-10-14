class Solution {
public:
    int from[1001];
    int dp[1001];
    int countDiff(string s1, string s2) {
        int sz = s1.size(), c = 0;
        for (int i = 0; i < sz; i++) {
            if (s1[i] != s2[i]) c++;
        }
        return c;
    }
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        int Max = 0, Maxi;
        for (int i = 0; i < n; i++) {
            string currWord = words[i];
            int currGrp = groups[i];
            dp[i] = 1; from[i] = -1;
            for (int j = 0; j < i; j++) {
                if (words[j].size() == currWord.size() && currGrp != groups[j] &&countDiff(words[j], currWord) == 1 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    from[i] = j;
                }
            }
            if (dp[i] > Max) {
                Max = dp[i], Maxi = i;
            }
        }
        vector<string> res;
        while (Maxi != -1) {
            res.push_back(words[Maxi]);
            Maxi = from[Maxi];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};