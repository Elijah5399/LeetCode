class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '*') {
                stk.pop();
            } else {
                stk.push(c);
            }
        }
        string ans = "";
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};