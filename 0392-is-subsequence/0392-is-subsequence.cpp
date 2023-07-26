class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lens = s.size(), lent = t.size();
        int i = 0;
        for (int j = 0; j < lent; j++) {
            if (t[j] == s[i]) {
                i++;
            }
        }
        return i == lens;
    }
};