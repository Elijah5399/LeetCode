class Solution {
public:
    string decodeAtIndex(string s, int k) {
        using ll = long long;
        stack<ll> stk;
        stk.push(0);
        for (char c : s) {
            if (isdigit(c)) {
                stk.push(stk.top() * (c - '0'));
            } else {
                stk.push(stk.top() + 1);
            }
        }
        int sz = s.length();
        while (!stk.empty()) {
            k %= stk.top();
            if (k == 0 && isalpha(s[sz - 1])) {
                return string(1,s[sz - 1]);
            }
            sz--;
            stk.pop();
        }
        return "wtf";
    }
};