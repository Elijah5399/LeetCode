class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        queue<vector<int>> q;
        vector<vector<bool>> visited;
        for (int i = 0; i < m; i++) {
            visited.push_back(vector<bool>(n, false));
        }
        int start_row = entrance[0], start_col = entrance[1];
        visited[start_row][start_col] = true;
        for (auto dir : dirs) {
            int next_row = start_row + dir[0], next_col = start_col + dir[1];
            if (next_row >= 0 && next_row < m && next_col >= 0 && next_col < n && maze[next_row][next_col] == '.') {
                q.push({next_row, next_col, 1});
            }
        }
        while (!q.empty()) {
            vector<int> next = q.front();
            q.pop();
            int curr_row = next[0], curr_col = next[1], steps = next[2];
            if (curr_row == 0 || curr_col == 0 || curr_row == m - 1 || curr_col == n - 1) {
                return steps;
            }
            for (auto dir : dirs) {
                int next_row = curr_row + dir[0], next_col = curr_col + dir[1];
                if (next_row >= 0 && next_row < m && next_col >= 0 && next_col < n && !visited[next_row][next_col] && maze[next_row][next_col] == '.') {
                    q.push({next_row, next_col, steps + 1});
                    visited[next_row][next_col] = true;
                }
            }
        }
        return -1;
    }
};