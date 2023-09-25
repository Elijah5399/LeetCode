class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> m;
        for (char c : t) {
            m[c]++;
        }
        for (char c : s) {
            m[c]--;
        }
        for (auto& p : m) {
            if (p.second == 1) {
                return p.first;
            }
        }
        return 'a';
    }
};