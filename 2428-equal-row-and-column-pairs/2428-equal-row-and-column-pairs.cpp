class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int res = 0;
        for (int row = 0; row < grid.size(); row++) {
            //for each row
            for (int col = 0; col < grid.size(); col++) {
                //for each of its corresponding cols
                for (int index = 0; index < grid.size(); index++) {
                    if (grid[row][index] != grid[index][col]) break;
                    if (index == grid.size() - 1) res++;
                }
            }
        }
        return res;
    }
};