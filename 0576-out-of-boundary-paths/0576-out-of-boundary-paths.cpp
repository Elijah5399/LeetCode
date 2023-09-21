class Solution {
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int MOD = 1000000007;
public:
    int findPaths(int rows, int cols, int maxMove, int startRow, int startCol) {
        if (maxMove == 0) return 0;
        vector<vector<int>> prev(rows, vector<int>(cols, 0));
        vector<vector<int>> cum(rows, vector<int>(cols, 0));
        vector<vector<int>> curr(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++) {
            prev[i][0]++;
            prev[i][cols - 1]++;
            cum[i][0]++;
            cum[i][cols - 1]++;
        }
        for (int j = 0; j < cols; j++) {
            prev[0][j]++;
            prev[rows - 1][j]++;
            cum[0][j]++;
            cum[rows - 1][j]++;
        }
        while (maxMove > 1) {
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    for (auto& dir : dirs) {
                        int new_x = j + dir[0], new_y = i + dir[1];
                        if (new_x >= 0 && new_y >= 0 && new_x < cols && new_y < rows) {
                            curr[i][j] += prev[new_y][new_x];
                            curr[i][j] %= MOD;
                        }
                    }
                }
            }
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cum[i][j] += curr[i][j];
                    cum[i][j] %= MOD;
                }
            }
            prev = curr;
            curr = vector<vector<int>>(rows, vector<int>(cols, 0));
            maxMove--;
        }
        return cum[startRow][startCol];
    }
};