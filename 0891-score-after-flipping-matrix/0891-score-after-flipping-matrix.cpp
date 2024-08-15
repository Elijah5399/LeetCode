/*
GREEDY APPROACH
1. Make all the rows start with 1
2. Iterate over all the columns from left to right, making more 1s than 0s on the way
-> flipping col 0 and not flipping col 0 will give the same result. This is because
flipping all rows & cols has the same effect as not flipping all rows & cols
*/

class Solution {
public:
    int n; int m;
    void fliprow(vector<vector<int>>& grid, int r) {
        for (int j = 0; j < m; j++) {
            grid[r][j] = !grid[r][j];
        }
    }
    void flipcol(vector<vector<int>>& grid, int c) {
        for (int i = 0; i < n; i++) {
            grid[i][c] = !grid[i][c];
        }
    }
    int matrixScore(vector<vector<int>>& grid) {
        n = grid.size(); 
        m = grid[0].size();
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0) {
                fliprow(grid, i);
            }
        }
        for (int j = 1; j < m; j++) {
            int ones = 0;
            for (int i = 0; i < n; i++) {
                ones += grid[i][j];
            }
            if (ones <= (int) (n / 2)) {
                flipcol(grid, j);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            string curr = "";
            for (int j = 0; j < m; j++)
                curr += grid[i][j] == 0 ? "0" : "1";
            res += stoi(curr, nullptr, 2);
        }
        return res;
    }
};