class Solution {
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        using tiii = tuple<int, int, int>;
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<int>> eff(rows, vector<int>(cols, INT_MAX));
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        priority_queue<tiii, vector<tiii>, greater<tiii>> pq;
        eff[0][0] = heights[0][0];
        pq.push({0, 0, 0});
        while (!pq.empty()) {
            auto next = pq.top();
            pq.pop();
            if (visited[get<2>(next)][get<1>(next)]) continue;
            visited[get<2>(next)][get<1>(next)] = true;
            for (auto& dir : dirs) {
                if (get<1>(next) == cols - 1 && get<2>(next) == rows - 1) {
                    return get<0>(next);
                }
                int new_x = get<1>(next) + dir[0], new_y = get<2>(next) + dir[1];
                if (new_x >= 0 && new_x < cols && new_y >= 0 && new_y < rows) {
                    tiii toAdd = make_tuple(max(get<0>(next), abs(heights[new_y][new_x] - heights[get<2>(next)][get<1>(next)])), new_x, new_y);
                    pq.push(toAdd);
                }
            }
        }
        return -1;
    }
};