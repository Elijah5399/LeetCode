class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        map<int, vector<int>> adjList;
        map<int, long long> sums;
        for (auto& x : edges) {
            int f = x[0], s = x[1];
            adjList[f].push_back(s);
            adjList[s].push_back(f);
        }
        initSums(adjList, values, 0, -1, sums);
        return dfs(adjList, n, values, k, 0, -1, sums);
    }
    int dfs(map<int, vector<int>>& adjList, int n, vector<int>& values, int k, int node, int parent, map<int, long long>& sums) {
        int res = 0;
        if (sums[node] % k == 0) res++;
        for (auto& other : adjList[node]) {
            if (other == parent) continue;
            res += dfs(adjList, n, values, k, other, node, sums);
        }
        return res;
    }
    long long initSums(map<int, vector<int>>& adjList, vector<int>& values, int node, int parent, map<int, long long>& sums) {
        long long res = values[node];
        for (auto& other : adjList[node]) {
            if (other == parent) continue;
            res += initSums(adjList, values, other, node, sums);
        }
        sums[node] = res;
        return res;
    }
};