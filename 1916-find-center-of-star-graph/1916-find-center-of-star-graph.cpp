class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        set<int> x;
        x.insert(edges[0][0]);
        x.insert(edges[0][1]);
        if (x.count(edges[1][0])) {
            return edges[1][0];
        }
        return edges[1][1];
    }
};