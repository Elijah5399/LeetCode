class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        unordered_set<int> s;
        bool changed = false;
        while (true) {
            for (int i = 0; i < n; i++) {
                if (!visited[i] && (s.contains(i) || i == 0)) {
                    changed = true;
                    visited[i] = true;
                    for (auto x : rooms[i]) {
                        s.insert(x);
                    }
                }
            }
            if (!changed) break;
            changed = false;
        }
        for (auto a : visited) {
            if (!a) return false;
        }
        return true;
    }
};