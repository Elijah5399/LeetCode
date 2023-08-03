class Solution {
private:
    void dfs(int curr, vector<vector<int>>& isConnected, vector<bool>& visited, int n) {
        //cout << "dfs on index: " << curr << endl;
        vector<int> connections = isConnected[curr];
        visited[curr] = true;
        for (int i = 0; i < n; i++) {
            if (connections[i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited, n);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int len = isConnected.size();
        vector<bool> visited(len, false);
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited, len);
                res++;
            }
        }
        return res;
    }
};