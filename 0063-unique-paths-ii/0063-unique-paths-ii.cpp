class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}};
    vector<vector<int>> memo;
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<bool>> visited;
        for (int i = 0; i < m; i++) {
            visited.push_back(vector<bool>(n, false));
            memo.push_back(vector<int>(n, -1));
        }
        return count(0, 0, obstacleGrid, visited, m, n);
    }
    int count(int y, int x, vector<vector<int>>& obstacleGrid, vector<vector<bool>>& visited, int m, int n) {
        if (obstacleGrid[y][x] == 1) {
            return 0;
        } else if (y == m - 1 && x == n - 1) {
            return 1;
        } else if (memo[y][x] != -1) {
            return memo[y][x];
        }
        int res = 0;
        for (vector<int> dir : dirs) {
            int new_y = y + dir[0], new_x = x + dir[1];
            if (new_y < m && new_x < n && !visited[new_y][new_x]) {
                visited[new_y][new_x] = true;
                res += count(new_y, new_x, obstacleGrid, visited, m, n);
                visited[new_y][new_x] = false;
            }
        }
        memo[y][x] = res;
        return res;
    }
};