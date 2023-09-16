class Solution {
    vector<vector<int>> graph;
    vector<vector<int>> revGraph;
    map<pair<int, int>, int> memo;

public:
    int dfs(int node, int parent) {
        int res = 0;
        if (memo.count({node, parent})) {
            return memo[{node, parent}];
        }
        for (int x : graph[node]) {
            if (x != parent) {
                res += dfs(x, node);
            }
        }
        for (int x : revGraph[node]) {
            if (x != parent) {
                res++;
                res += dfs(x, node);
            }
        }
        memo[{node, parent}] = res;
        return res;
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        graph = vector<vector<int>>(n, vector<int>());
        revGraph = vector<vector<int>>(n, vector<int>());
        for (auto& e : edges) {
            int from = e[0], to = e[1];
            graph[from].push_back(to);
            revGraph[to].push_back(from);
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            ans.push_back(dfs(i, -1));
        }
        return ans;
    }
};