class Solution {
public:
    int minChanges(string s) {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n / 2; i++) {
            if (s[2 * i] != s[2 * i + 1]) ans++;
        }
        return ans;
    }
};