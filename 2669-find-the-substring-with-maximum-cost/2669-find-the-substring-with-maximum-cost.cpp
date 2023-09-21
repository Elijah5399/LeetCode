class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = vals.size(), sl = s.length();
        map<char, int> c;
        for (int i = 0; i < n; i++) {
            c[chars[i]] = vals[i];
        }
        for (int i = 0; i <= 25; i++) {
            char cn = 'a' + i;
            if (!c.count(cn)) c[cn] = i + 1;
        }
        int local_max = 0, global_max = INT_MIN;
        for (int i = 0; i < sl; i++) {
            local_max = max(local_max + c[s[i]], c[s[i]]);
            global_max = max(local_max, global_max);
        }
        return max(0,global_max);
    }
};