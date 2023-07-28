class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for (auto x : arr) {
            m[x]++;
        }
        unordered_set<int> s;
        for (pair<int, int> p : m) {
            if (s.count(p.second)) {
                return false;
            }
            s.insert(p.second);
        }
        return true;
    }
};