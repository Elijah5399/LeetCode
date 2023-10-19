class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss;
        stack<char> tt;
        for (auto& c : s) {
            if (c == '#') {
                if (!ss.empty()) ss.pop();
            } else {
                ss.push(c);
            }
        }
        for (auto& c : t) {
            if (c == '#') {
                if (!tt.empty()) tt.pop();
            } else {
                tt.push(c);
            }
        }
        if (ss.size() != tt.size()) {
            return false;
        }
        while (!ss.empty()) {
            char f = ss.top(), s = tt.top();
            ss.pop();
            tt.pop();
            if (f != s) {
                return false;
            }
        }
        return true;
    }
};