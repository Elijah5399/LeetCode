class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        set<char> v;
        stack<char> stk;
        vector<int> last_occ(26, -1);
        for (int i = 0; i < n; i++) {
            last_occ[s[i] - 'a'] = i;
        }
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (!v.count(c)) {
                while (!stk.empty() && stk.top() > c && last_occ[stk.top() - 'a'] > i) {
                    v.erase(stk.top());
                    stk.pop();
                }
                v.insert(c);
                stk.push(c);
            }
        }
        string res = "";
        while (!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        return res;
    }
};