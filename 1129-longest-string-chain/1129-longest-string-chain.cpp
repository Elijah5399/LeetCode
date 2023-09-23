class Solution {
public:
    bool isSub(string f, string s) {
        if (f.size() != s.size() - 1) return false;
        bool x = true;
        int l = s.size();
        for (int i = 0; i < l; i++) {
            if (x) {
                if (i >= f.size() || f[i] == s[i]) {
                    continue;
                } else {
                    x = false;
                }
            } else {
                if (f[i - 1] == s[i]) {
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
    static bool comp(string& first, string& second) {
        if (first.size() != second.size()) {
            return first.size() < second.size();
        }
        return first.compare(second) < 0;
    }
    int longestStrChain(vector<string>& words) {
        map<string, int> m;
        sort(words.begin(), words.end(), comp);
        m[""] = 0;
        int res = 1;
        for (auto& word : words) {
            m[word] = 1;
            cout << "word is: " << word << endl;
            for (auto& x : m) {
                if (isSub(x.first, word)) {
                    m[word] = max(m[x.first] + 1, m[word]);
                    res = max(res, m[word]);
                }
            }
        }
        for (auto& x : m) {
            cout << "word: " << x.first << ", num: " << x.second << endl;
        }
        return res;
    }
};