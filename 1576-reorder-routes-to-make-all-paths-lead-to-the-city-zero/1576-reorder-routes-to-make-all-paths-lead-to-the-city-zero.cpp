class Solution {
public:
    int res = 0;
    void dfs(int curr, int prev, vector<bool>& visited, unordered_map<int, vector<int>>& adjList1, unordered_map<int, unordered_set<int>>& conn) {
        visited[curr] = true;
        if (conn[prev].count(curr)) {
            res++;
        }
        for (int x : adjList1[curr]) {
            if (!visited[x]) {
                dfs(x, curr, visited, adjList1, conn);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> adjList1;
        unordered_map<int, unordered_set<int>> conn; 
        //conn stores outwards edges
        for (int i = 0; i < n; i++) {
            adjList1.insert({i, vector<int>()});
            conn.insert({i, unordered_set<int>()});
        }
        for (vector<int> e : connections) {
            int first = e[0], second = e[1];
            adjList1[first].push_back(second);
            adjList1[second].push_back(first);
            conn[first].insert(second);
        }
        vector<bool> visited(n, false);
        visited[0] = true;
        for (int x : adjList1[0]) {
            dfs(x, 0, visited, adjList1, conn);
        }
        return res;
    }
};