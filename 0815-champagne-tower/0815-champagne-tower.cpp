class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double m[102][102];
        for (int i = 0; i < 102; i++) {
            for (int j = 0; j < 102; j++) {
                m[i][j] = 0.0;
            }
        }
        m[0][0] = poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                double curr = m[i][j];
                m[i + 1][j] += max((curr - 1) / 2, 0.0);
                m[i + 1][j + 1] += max((curr - 1) / 2, 0.0);
            }
        }
        return min(1.0, m[query_row][query_glass]);
    }
};